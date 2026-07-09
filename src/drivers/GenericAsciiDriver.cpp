#include "GenericAsciiDriver.h"

QString GenericAsciiDriver::name() const { return "Generic ASCII Driver"; }
bool GenericAsciiDriver::connectDevice(const AnalyzerConfig& config) { cfg = config; return serial.open(config.endpoint, config.baudRate); }
void GenericAsciiDriver::disconnectDevice() { serial.close(); }
bool GenericAsciiDriver::isConnected() const { return serial.isOpen(); }
AnalyzerReading GenericAsciiDriver::poll() {
    QByteArray raw = serial.query(cfg.pollCommand.toUtf8());
    return parseKeyValueFrame(raw, cfg.vendor, cfg.model);
}
AnalyzerReading GenericAsciiDriver::parseKeyValueFrame(const QByteArray& raw, const QString& vendor, const QString& model) {
    AnalyzerReading r; r.vendor=vendor; r.model=model; r.timestamp=QDateTime::currentDateTime(); r.rawFrame=QString::fromUtf8(raw); r.status="OK";
    QString s=QString::fromUtf8(raw).trimmed();
    const auto parts=s.split(',', Qt::SkipEmptyParts);
    for(const QString& p: parts){
        auto kv=p.split('=', Qt::SkipEmptyParts);
        if(kv.size()==2){ bool ok=false; double v=kv[1].trimmed().toDouble(&ok); if(ok) r.values[kv[0].trimmed().toUpper()] = v; }
    }
    r.valid=!r.values.isEmpty();
    return r;
}

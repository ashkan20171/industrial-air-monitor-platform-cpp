#include "ESADriver.h"
QString ESADriver::name() const { return "ESA Driver"; }
AnalyzerReading ESADriver::poll() {
    QByteArray raw = serial.query(cfg.pollCommand.isEmpty() ? QByteArray("STATUS?\r\n") : cfg.pollCommand.toUtf8());
    return parseKeyValueFrame(raw, "ESA", cfg.model.isEmpty()?"Template":cfg.model);
}

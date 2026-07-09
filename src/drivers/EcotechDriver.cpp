#include "EcotechDriver.h"
QString EcotechDriver::name() const { return "Ecotech Driver"; }
AnalyzerReading EcotechDriver::poll() {
    QByteArray raw = serial.query(cfg.pollCommand.isEmpty() ? QByteArray("DATA?\r\n") : cfg.pollCommand.toUtf8());
    AnalyzerReading r = parseKeyValueFrame(raw, "Ecotech", cfg.model.isEmpty()?"Template":cfg.model);
    if(r.values.contains("O3")) r.status = r.values["O3"] > 120 ? "ALARM" : "OK";
    return r;
}

#include "BAMDriver.h"
QString BAMDriver::name() const { return "BAM / Met One Driver"; }
AnalyzerReading BAMDriver::poll() {
    QByteArray raw = serial.query(cfg.pollCommand.isEmpty() ? QByteArray("LAST?\r\n") : cfg.pollCommand.toUtf8());
    AnalyzerReading r = parseKeyValueFrame(raw, "BAM/MetOne", cfg.model.isEmpty()?"BAM Template":cfg.model);
    if(r.values.contains("PM25") && r.values["PM25"] > 35) r.status = "WARNING";
    if(r.values.contains("PM25") && r.values["PM25"] > 55) r.status = "DANGER";
    return r;
}

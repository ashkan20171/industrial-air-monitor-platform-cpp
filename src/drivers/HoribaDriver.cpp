#include "HoribaDriver.h"
QString HoribaDriver::name() const { return "Horiba Driver"; }
AnalyzerReading HoribaDriver::poll() {
    QByteArray raw = serial.query(cfg.pollCommand.isEmpty() ? QByteArray("MEAS?\r\n") : cfg.pollCommand.toUtf8());
    AnalyzerReading r = parseKeyValueFrame(raw, "Horiba", cfg.model.isEmpty()?"Template":cfg.model);
    if(r.values.contains("NOX") && r.values["NOX"] > 200) r.status = "HIGH_NOX";
    return r;
}

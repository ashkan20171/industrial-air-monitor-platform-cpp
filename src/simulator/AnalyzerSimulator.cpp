#include "AnalyzerSimulator.h"
#include <QDateTime>
#include <QRandomGenerator>

AnalyzerReading AnalyzerSimulator::simulate(const QString& vendor, const QString& model) const {
    AnalyzerReading r;
    r.vendor = vendor;
    r.model = model;
    r.timestamp = QDateTime::currentDateTime();
    r.values["PM25"] = 10 + QRandomGenerator::global()->bounded(60.0);
    r.values["PM10"] = 20 + QRandomGenerator::global()->bounded(80.0);
    r.values["NO2"] = 5 + QRandomGenerator::global()->bounded(40.0);
    r.values["NOX"] = 10 + QRandomGenerator::global()->bounded(90.0);
    r.values["O3"] = 10 + QRandomGenerator::global()->bounded(120.0);
    r.values["CO"] = QRandomGenerator::global()->bounded(5.0);
    r.rawFrame = QString("PM25=%1,PM10=%2,NO2=%3,NOX=%4,O3=%5,CO=%6")
        .arg(r.values["PM25"]).arg(r.values["PM10"]).arg(r.values["NO2"]).arg(r.values["NOX"]).arg(r.values["O3"]).arg(r.values["CO"]);
    r.status = "SIMULATED";
    r.valid = true;
    return r;
}

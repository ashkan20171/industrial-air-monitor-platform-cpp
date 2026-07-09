#pragma once
#include <QString>
#include <QDateTime>
#include <QMap>

struct AnalyzerReading {
    QString vendor;
    QString model;
    QString connectionName;
    QDateTime timestamp;
    QMap<QString,double> values;
    QString status;
    QString rawFrame;
    bool valid = false;
};

#pragma once
#include "core/AnalyzerReading.h"
#include <QString>

class AnalyzerSimulator {
public:
    AnalyzerReading simulate(const QString& vendor, const QString& model) const;
};

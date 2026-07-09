#pragma once
#include <QString>
#include "core/AnalyzerReading.h"
#include "core/AnalyzerConfig.h"

class IAnalyzerDriver {
public:
    virtual ~IAnalyzerDriver() = default;
    virtual QString name() const = 0;
    virtual bool connectDevice(const AnalyzerConfig& config) = 0;
    virtual void disconnectDevice() = 0;
    virtual bool isConnected() const = 0;
    virtual AnalyzerReading poll() = 0;
};

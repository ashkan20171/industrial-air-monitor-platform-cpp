#pragma once
#include "IAnalyzerDriver.h"
#include "protocols/SerialClient.h"

class ModbusAnalyzerDriver : public IAnalyzerDriver {
public:
    QString name() const override;
    bool connectDevice(const AnalyzerConfig& config) override;
    void disconnectDevice() override;
    bool isConnected() const override;
    AnalyzerReading poll() override;
private:
    SerialClient serial;
    AnalyzerConfig cfg;
};

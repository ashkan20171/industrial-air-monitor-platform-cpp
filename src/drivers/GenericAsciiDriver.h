#pragma once
#include "IAnalyzerDriver.h"
#include "protocols/SerialClient.h"

class GenericAsciiDriver : public IAnalyzerDriver {
public:
    QString name() const override;
    bool connectDevice(const AnalyzerConfig& config) override;
    void disconnectDevice() override;
    bool isConnected() const override;
    AnalyzerReading poll() override;
protected:
    SerialClient serial;
    AnalyzerConfig cfg;
    AnalyzerReading parseKeyValueFrame(const QByteArray& raw, const QString& vendor, const QString& model);
};

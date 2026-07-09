#pragma once
#include "GenericAsciiDriver.h"
class EcotechDriver : public GenericAsciiDriver {
public:
    QString name() const override;
    AnalyzerReading poll() override;
};

#pragma once
#include "GenericAsciiDriver.h"
class BAMDriver : public GenericAsciiDriver {
public:
    QString name() const override;
    AnalyzerReading poll() override;
};

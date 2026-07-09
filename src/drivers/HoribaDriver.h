#pragma once
#include "GenericAsciiDriver.h"
class HoribaDriver : public GenericAsciiDriver {
public:
    QString name() const override;
    AnalyzerReading poll() override;
};

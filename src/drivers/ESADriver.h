#pragma once
#include "GenericAsciiDriver.h"
class ESADriver : public GenericAsciiDriver {
public:
    QString name() const override;
    AnalyzerReading poll() override;
};

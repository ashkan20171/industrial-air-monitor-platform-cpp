#pragma once
#include <memory>
#include <QString>
#include "IAnalyzerDriver.h"

class AnalyzerFactory {
public:
    static std::unique_ptr<IAnalyzerDriver> create(const QString& vendor, const QString& connectionType);
};

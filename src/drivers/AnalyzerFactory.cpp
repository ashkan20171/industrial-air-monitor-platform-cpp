#include "AnalyzerFactory.h"
#include "EcotechDriver.h"
#include "BAMDriver.h"
#include "HoribaDriver.h"
#include "ESADriver.h"
#include "GenericAsciiDriver.h"
#include "ModbusAnalyzerDriver.h"

std::unique_ptr<IAnalyzerDriver> AnalyzerFactory::create(const QString& vendor, const QString& connectionType) {
    const QString v = vendor.trimmed().toLower();
    const QString c = connectionType.trimmed().toLower();
    if(c.contains("modbus")) return std::make_unique<ModbusAnalyzerDriver>();
    if(v == "ecotech") return std::make_unique<EcotechDriver>();
    if(v == "bam" || v == "metone" || v == "met one") return std::make_unique<BAMDriver>();
    if(v == "horiba") return std::make_unique<HoribaDriver>();
    if(v == "esa") return std::make_unique<ESADriver>();
    return std::make_unique<GenericAsciiDriver>();
}

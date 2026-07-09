#include "ModbusAnalyzerDriver.h"
#include "protocols/ModbusFrame.h"

QString ModbusAnalyzerDriver::name() const { return "Generic Modbus Analyzer Driver"; }
bool ModbusAnalyzerDriver::connectDevice(const AnalyzerConfig& config) { cfg = config; return serial.open(config.endpoint, config.baudRate); }
void ModbusAnalyzerDriver::disconnectDevice() { serial.close(); }
bool ModbusAnalyzerDriver::isConnected() const { return serial.isOpen(); }
AnalyzerReading ModbusAnalyzerDriver::poll() {
    QByteArray req = ModbusFrame::readHoldingRegistersRtu(static_cast<quint8>(cfg.slaveId), static_cast<quint16>(cfg.startRegister), static_cast<quint16>(cfg.registerCount));
    QByteArray raw = serial.query(req);
    AnalyzerReading r; r.vendor=cfg.vendor; r.model=cfg.model; r.timestamp=QDateTime::currentDateTime(); r.rawFrame=raw.toHex(' '); r.status="MODBUS_RAW";
    if(raw.size() >= 7) {
        r.valid = true;
        r.values["REG_COUNT"] = cfg.registerCount;
        r.values["RAW_BYTES"] = raw.size();
    }
    return r;
}

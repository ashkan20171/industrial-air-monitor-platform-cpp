#pragma once
#include <QByteArray>

class ModbusFrame {
public:
    static quint16 crc16(const QByteArray& data);
    static QByteArray readHoldingRegistersRtu(quint8 slaveId, quint16 startAddress, quint16 quantity);
};

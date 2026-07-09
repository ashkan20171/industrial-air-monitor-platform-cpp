#include "ModbusFrame.h"

quint16 ModbusFrame::crc16(const QByteArray& data) {
    quint16 crc = 0xFFFF;
    for (unsigned char b : data) {
        crc ^= b;
        for (int i=0;i<8;++i) crc = (crc & 1) ? (crc >> 1) ^ 0xA001 : (crc >> 1);
    }
    return crc;
}

QByteArray ModbusFrame::readHoldingRegistersRtu(quint8 slaveId, quint16 startAddress, quint16 quantity) {
    QByteArray f;
    f.append(char(slaveId));
    f.append(char(0x03));
    f.append(char((startAddress >> 8) & 0xFF));
    f.append(char(startAddress & 0xFF));
    f.append(char((quantity >> 8) & 0xFF));
    f.append(char(quantity & 0xFF));
    quint16 c = crc16(f);
    f.append(char(c & 0xFF));
    f.append(char((c >> 8) & 0xFF));
    return f;
}

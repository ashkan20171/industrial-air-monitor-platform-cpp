#include "SerialClient.h"

SerialClient::SerialClient(QObject* parent): QObject(parent) {}

bool SerialClient::open(const QString& portName, int baudRate, QSerialPort::Parity parity,
                        QSerialPort::DataBits dataBits, QSerialPort::StopBits stopBits) {
    serial.setPortName(portName);
    serial.setBaudRate(baudRate);
    serial.setParity(parity);
    serial.setDataBits(dataBits);
    serial.setStopBits(stopBits);
    return serial.open(QIODevice::ReadWrite);
}

void SerialClient::close(){ serial.close(); }
bool SerialClient::isOpen() const { return serial.isOpen(); }
QByteArray SerialClient::query(const QByteArray& command, int timeoutMs){
    if(!serial.isOpen()) return {};
    serial.write(command);
    serial.flush();
    if(!serial.waitForReadyRead(timeoutMs)) return {};
    QByteArray data=serial.readAll();
    while(serial.waitForReadyRead(100)) data += serial.readAll();
    return data;
}

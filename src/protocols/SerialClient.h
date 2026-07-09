#pragma once
#include <QObject>
#include <QSerialPort>

class SerialClient : public QObject {
    Q_OBJECT
public:
    explicit SerialClient(QObject* parent=nullptr);
    bool open(const QString& portName, int baudRate=9600, QSerialPort::Parity parity=QSerialPort::NoParity,
              QSerialPort::DataBits dataBits=QSerialPort::Data8, QSerialPort::StopBits stopBits=QSerialPort::OneStop);
    void close();
    bool isOpen() const;
    QByteArray query(const QByteArray& command, int timeoutMs=1500);
private:
    QSerialPort serial;
};

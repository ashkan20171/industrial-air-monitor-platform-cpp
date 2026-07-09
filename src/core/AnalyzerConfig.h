#pragma once
#include <QString>

struct AnalyzerConfig {
    QString vendor;
    QString model;
    QString connectionType; // serial, tcp, modbus_rtu, modbus_tcp, simulator
    QString endpoint;       // COM3 or 192.168.1.100:4001
    int baudRate = 9600;
    int pollIntervalSec = 10;
    int slaveId = 1;
    int startRegister = 0;
    int registerCount = 8;
    QString pollCommand = "DATA?\r\n";
};

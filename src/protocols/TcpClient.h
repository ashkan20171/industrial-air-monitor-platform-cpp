#pragma once
#include <QObject>
#include <QTcpSocket>

class TcpClient : public QObject {
    Q_OBJECT
public:
    explicit TcpClient(QObject* parent=nullptr);
    bool connectToHost(const QString& host, quint16 port, int timeoutMs=2000);
    void close();
    bool isOpen() const;
    QByteArray query(const QByteArray& command, int timeoutMs=1500);
private:
    QTcpSocket socket;
};

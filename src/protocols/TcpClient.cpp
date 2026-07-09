#include "TcpClient.h"

TcpClient::TcpClient(QObject* parent): QObject(parent) {}
bool TcpClient::connectToHost(const QString& host, quint16 port, int timeoutMs){
    socket.connectToHost(host, port);
    return socket.waitForConnected(timeoutMs);
}
void TcpClient::close(){ socket.close(); }
bool TcpClient::isOpen() const { return socket.state()==QAbstractSocket::ConnectedState; }
QByteArray TcpClient::query(const QByteArray& command, int timeoutMs){
    if(!isOpen()) return {};
    socket.write(command);
    socket.flush();
    if(!socket.waitForReadyRead(timeoutMs)) return {};
    QByteArray data=socket.readAll();
    while(socket.waitForReadyRead(100)) data += socket.readAll();
    return data;
}

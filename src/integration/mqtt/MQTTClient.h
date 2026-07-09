#pragma once
#include <string>

namespace integration {

class MQTTClient {
public:
    bool connect(const std::string& host, int port, const std::string& clientId);
    bool publish(const std::string& topic, const std::string& payloadJson, int qos = 1, bool retained = false);
    void disconnect();
    bool isConnected() const;
private:
    bool connected_ = false;
    std::string host_;
    int port_ = 1883;
};

}

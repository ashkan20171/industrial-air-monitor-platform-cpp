#pragma once
#include <string>

struct AnalyzerReading;

namespace integration {

class OPCUAServer {
public:
    bool start(int port = 4840);
    void publishReading(const AnalyzerReading& reading);
    void publishAlarm(const std::string& alarmId, const std::string& severity, const std::string& message);
    void stop();
    bool isRunning() const;
private:
    bool running_ = false;
    int port_ = 4840;
};

}

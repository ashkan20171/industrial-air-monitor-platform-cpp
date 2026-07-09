#include "OPCUAServer.h"

namespace integration {

bool OPCUAServer::start(int port) {
    port_ = port;
    running_ = true;
    // Production implementation: integrate open62541, create namespace and device nodes.
    return running_;
}

void OPCUAServer::publishReading(const AnalyzerReading&) {
    if (!running_) return;
    // Production implementation: update OPC-UA variable nodes.
}

void OPCUAServer::publishAlarm(const std::string&, const std::string&, const std::string&) {
    if (!running_) return;
    // Production implementation: publish alarm condition/event nodes.
}

void OPCUAServer::stop() { running_ = false; }
bool OPCUAServer::isRunning() const { return running_; }

}

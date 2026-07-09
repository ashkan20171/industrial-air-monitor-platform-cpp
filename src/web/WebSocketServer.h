#pragma once
#include <string>
namespace ashkan::web { class WebSocketServer{public: void publish(const std::string& channel,const std::string& payload); std::string lastPayload() const; private: std::string m_last;};}

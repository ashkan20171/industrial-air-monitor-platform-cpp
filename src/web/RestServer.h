#pragma once
#include <atomic>
#include <string>
namespace ashkan::web { class RestServer{public: explicit RestServer(int port=8080); void start(); void stop(); bool running() const; std::string statusJson() const; private:int m_port; std::atomic<bool> m_running{false};};}

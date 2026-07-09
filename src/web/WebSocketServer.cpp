#include "WebSocketServer.h"
namespace ashkan::web { void WebSocketServer::publish(const std::string&,const std::string& p){m_last=p;} std::string WebSocketServer::lastPayload() const{return m_last;} }

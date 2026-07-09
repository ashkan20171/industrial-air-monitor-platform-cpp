#pragma once
#include <string>
#include <queue>

namespace edge {

class EdgeGateway {
public:
    void bufferMessage(const std::string& payloadJson);
    bool hasBufferedMessages() const;
    std::string popNextMessage();
private:
    std::queue<std::string> buffer_;
};

}

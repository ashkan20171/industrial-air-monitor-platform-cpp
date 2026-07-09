#include "EdgeGateway.h"

namespace edge {

void EdgeGateway::bufferMessage(const std::string& payloadJson) { buffer_.push(payloadJson); }
bool EdgeGateway::hasBufferedMessages() const { return !buffer_.empty(); }
std::string EdgeGateway::popNextMessage() {
    if (buffer_.empty()) return {};
    auto msg = buffer_.front();
    buffer_.pop();
    return msg;
}

}

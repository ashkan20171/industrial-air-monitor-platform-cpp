#pragma once
#include <string>
#include <vector>

namespace security {

struct AuditEvent {
    std::string timestampUtc;
    std::string username;
    std::string action;
    std::string entity;
    std::string result;
};

class AuditTrail {
public:
    void record(const AuditEvent& event);
    const std::vector<AuditEvent>& events() const;
private:
    std::vector<AuditEvent> events_;
};

}

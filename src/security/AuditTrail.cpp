#include "AuditTrail.h"

namespace security {

void AuditTrail::record(const AuditEvent& event) {
    events_.push_back(event);
}

const std::vector<AuditEvent>& AuditTrail::events() const {
    return events_;
}

}

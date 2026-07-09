#include "HealthCheck.h"

namespace observability {

void HealthCheck::add(const HealthItem& item) { items_.push_back(item); }
bool HealthCheck::overallHealthy() const {
    for (const auto& i : items_) if (!i.healthy) return false;
    return true;
}
std::vector<HealthItem> HealthCheck::items() const { return items_; }

}

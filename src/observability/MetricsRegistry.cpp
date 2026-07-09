#include "MetricsRegistry.h"

namespace observability {

void MetricsRegistry::increment(const std::string& name, double value) { metrics_[name] += value; }
void MetricsRegistry::setGauge(const std::string& name, double value) { metrics_[name] = value; }
double MetricsRegistry::get(const std::string& name) const {
    auto it = metrics_.find(name);
    return it == metrics_.end() ? 0.0 : it->second;
}

}

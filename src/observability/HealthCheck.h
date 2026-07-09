#pragma once
#include <string>
#include <vector>

namespace observability {

struct HealthItem {
    std::string component;
    bool healthy;
    std::string message;
};

class HealthCheck {
public:
    void add(const HealthItem& item);
    bool overallHealthy() const;
    std::vector<HealthItem> items() const;
private:
    std::vector<HealthItem> items_;
};

}

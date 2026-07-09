#pragma once
#include <map>
#include <string>

namespace observability {

class MetricsRegistry {
public:
    void increment(const std::string& name, double value = 1.0);
    void setGauge(const std::string& name, double value);
    double get(const std::string& name) const;
private:
    std::map<std::string, double> metrics_;
};

}

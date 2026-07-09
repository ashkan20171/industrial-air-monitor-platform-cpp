#pragma once
#include <string>
#include <vector>

namespace compliance {

struct ComplianceResult {
    std::string pollutant;
    bool valid;
    double average;
    double completenessPercent;
    std::string standard;
    std::string note;
};

class ComplianceEngine {
public:
    ComplianceResult evaluateHourlyAverage(const std::string& pollutant, const std::vector<double>& values, const std::string& standard = "EU");
};

}

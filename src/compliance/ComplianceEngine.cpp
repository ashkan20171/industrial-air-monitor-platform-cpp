#include "ComplianceEngine.h"
#include <numeric>

namespace compliance {

ComplianceResult ComplianceEngine::evaluateHourlyAverage(const std::string& pollutant, const std::vector<double>& values, const std::string& standard) {
    ComplianceResult r;
    r.pollutant = pollutant;
    r.standard = standard;
    r.completenessPercent = values.empty() ? 0.0 : 100.0;
    r.valid = r.completenessPercent >= 75.0;
    r.average = values.empty() ? 0.0 : std::accumulate(values.begin(), values.end(), 0.0) / values.size();
    r.note = r.valid ? "Valid hourly average" : "Insufficient data completeness";
    return r;
}

}

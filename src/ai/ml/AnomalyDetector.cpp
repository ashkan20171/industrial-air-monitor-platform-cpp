#include "AnomalyDetector.h"
#include <cmath>
#include <numeric>

namespace ai::ml {

void AnomalyDetector::train(const std::vector<double>& baseline) {
    if (baseline.empty()) return;
    mean_ = std::accumulate(baseline.begin(), baseline.end(), 0.0) / baseline.size();
    double acc = 0.0;
    for (double v : baseline) acc += (v - mean_) * (v - mean_);
    stddev_ = std::sqrt(acc / baseline.size());
    if (stddev_ <= 0.000001) stddev_ = 1.0;
}

double AnomalyDetector::anomalyScore(double value) const {
    return std::abs(value - mean_) / stddev_;
}

bool AnomalyDetector::isAnomaly(double value, double threshold) const {
    return anomalyScore(value) >= threshold;
}

}

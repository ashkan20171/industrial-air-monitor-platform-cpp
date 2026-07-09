#pragma once
#include <vector>

namespace ai::ml {

class AnomalyDetector {
public:
    void train(const std::vector<double>& baseline);
    double anomalyScore(double value) const;
    bool isAnomaly(double value, double threshold = 3.0) const;
private:
    double mean_ = 0.0;
    double stddev_ = 1.0;
};

}

#pragma once
#include <deque>
#include <map>
#include <mutex>
#include <string>
#include <vector>
#include "../core/AnalyzerReading.h"

namespace ashkan::ai {
struct AnomalyEvent { std::string timestamp, deviceId, parameter, type, message; double value=0, score=0; };
class AIEngine {
public:
    explicit AIEngine(std::size_t windowSize = 30);
    std::vector<AnomalyEvent> onReading(const AnalyzerReading& reading);
    std::vector<AnomalyEvent> history() const;
private:
    std::string key(const AnalyzerReading& r) const;
    std::size_t m_windowSize;
    mutable std::mutex m_mutex;
    std::map<std::string, std::deque<double>> m_windows;
    std::vector<AnomalyEvent> m_history;
};
}

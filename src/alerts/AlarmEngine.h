#pragma once
#include <functional>
#include <map>
#include <mutex>
#include <string>
#include <vector>
#include "../core/AnalyzerReading.h"

namespace ashkan::alerts {

enum class AlarmLevel { INFO, WARNING, ALARM, CRITICAL };
std::string toString(AlarmLevel level);

struct AlarmRule {
    std::string deviceId;
    std::string parameter;
    double warningHigh = 0.0;
    double alarmHigh = 0.0;
    double criticalHigh = 0.0;
    double hysteresis = 0.0;
    bool enabled = true;
};

struct AlarmEvent {
    std::string timestamp;
    std::string deviceId;
    std::string parameter;
    double value = 0.0;
    AlarmLevel level = AlarmLevel::INFO;
    std::string message;
    bool acknowledged = false;
};

class AlarmEngine {
public:
    using AlarmCallback = std::function<void(const AlarmEvent&)>;
    void addRule(const AlarmRule& rule);
    void onReading(const AnalyzerReading& reading);
    void subscribe(AlarmCallback callback);
    std::vector<AlarmEvent> history() const;
    void acknowledgeAll();

private:
    std::string key(const std::string& device, const std::string& parameter) const;
    mutable std::mutex m_mutex;
    std::vector<AlarmRule> m_rules;
    std::vector<AlarmEvent> m_history;
    std::vector<AlarmCallback> m_callbacks;
};
}

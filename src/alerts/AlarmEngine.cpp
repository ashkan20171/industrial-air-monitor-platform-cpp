#include "AlarmEngine.h"
#include <sstream>

namespace ashkan::alerts {
std::string toString(AlarmLevel level) {
    switch(level){case AlarmLevel::INFO:return "INFO";case AlarmLevel::WARNING:return "WARNING";case AlarmLevel::ALARM:return "ALARM";case AlarmLevel::CRITICAL:return "CRITICAL";} return "INFO";
}

void AlarmEngine::addRule(const AlarmRule& rule){ std::lock_guard<std::mutex> l(m_mutex); m_rules.push_back(rule); }
std::string AlarmEngine::key(const std::string& d,const std::string& p) const { return d+":"+p; }

void AlarmEngine::onReading(const AnalyzerReading& r){
    std::vector<AlarmCallback> callbacks; AlarmEvent event; bool triggered=false;
    {
        std::lock_guard<std::mutex> l(m_mutex);
        for(const auto& rule:m_rules){
            if(!rule.enabled) continue;
            if((!rule.deviceId.empty() && rule.deviceId!=r.deviceId) || rule.parameter!=r.parameter) continue;
            AlarmLevel level=AlarmLevel::INFO;
            if(r.value>=rule.criticalHigh) level=AlarmLevel::CRITICAL;
            else if(r.value>=rule.alarmHigh) level=AlarmLevel::ALARM;
            else if(r.value>=rule.warningHigh) level=AlarmLevel::WARNING;
            else continue;
            std::ostringstream ss; ss<<"Parameter "<<r.parameter<<" on "<<r.deviceId<<" is "<<r.value<<" ["<<toString(level)<<"]";
            event={r.timestamp,r.deviceId,r.parameter,r.value,level,ss.str(),false};
            m_history.push_back(event); callbacks=m_callbacks; triggered=true; break;
        }
    }
    if(triggered) for(auto& cb:callbacks) if(cb) cb(event);
}
void AlarmEngine::subscribe(AlarmCallback cb){ std::lock_guard<std::mutex> l(m_mutex); m_callbacks.push_back(std::move(cb)); }
std::vector<AlarmEvent> AlarmEngine::history() const { std::lock_guard<std::mutex> l(m_mutex); return m_history; }
void AlarmEngine::acknowledgeAll(){ std::lock_guard<std::mutex> l(m_mutex); for(auto& e:m_history) e.acknowledged=true; }
}

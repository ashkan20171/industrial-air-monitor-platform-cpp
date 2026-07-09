#include "AIEngine.h"
#include <cmath>
#include <numeric>
#include <sstream>
namespace ashkan::ai {
AIEngine::AIEngine(std::size_t w):m_windowSize(w){}
std::string AIEngine::key(const AnalyzerReading& r) const { return r.deviceId+":"+r.parameter; }
std::vector<AnomalyEvent> AIEngine::onReading(const AnalyzerReading& r){
    std::lock_guard<std::mutex> l(m_mutex); std::vector<AnomalyEvent> events; auto& win=m_windows[key(r)];
    if(win.size()>=10){
        double mean=std::accumulate(win.begin(),win.end(),0.0)/win.size(); double var=0; for(double v:win)var+=(v-mean)*(v-mean); var/=win.size(); double sd=std::sqrt(var);
        double z=sd>1e-9?(r.value-mean)/sd:0;
        if(std::abs(z)>3.0){ std::ostringstream ss; ss<<"Z-score anomaly detected, z="<<z; events.push_back({r.timestamp,r.deviceId,r.parameter,"SPIKE",ss.str(),r.value,z}); }
        bool flat=true; for(double v:win) if(std::abs(v-r.value)>1e-6){flat=false;break;} if(flat && win.size()>=m_windowSize/2) events.push_back({r.timestamp,r.deviceId,r.parameter,"FLATLINE","Possible sensor failure: constant value",r.value,1});
        if(win.size()>=m_windowSize){ double first=win.front(), last=win.back(); double drift=last-first; if(std::abs(drift)>sd*4 && sd>1e-9) events.push_back({r.timestamp,r.deviceId,r.parameter,"DRIFT","Long-term drift suspected",r.value,drift}); }
    }
    win.push_back(r.value); while(win.size()>m_windowSize) win.pop_front();
    for(auto& e:events) m_history.push_back(e); return events;
}
std::vector<AnomalyEvent> AIEngine::history() const { std::lock_guard<std::mutex> l(m_mutex); return m_history; }
}

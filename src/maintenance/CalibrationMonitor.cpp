#include "CalibrationMonitor.h"
#include <cmath>
namespace ashkan::maintenance { void CalibrationMonitor::updateDrift(const std::string& d,double s){m_drift[d]=s;} HealthStatus CalibrationMonitor::status(const std::string& d) const{ auto it=m_drift.find(d); double s=it==m_drift.end()?0:it->second; std::string st=std::abs(s)>10?"MAINTENANCE_REQUIRED":"OK"; return {d,st, st=="OK"?"Device health is normal":"Calibration/drift check required",s,30}; }}

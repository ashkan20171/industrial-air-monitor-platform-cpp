#pragma once
#include <map>
#include <string>
namespace ashkan::maintenance { struct HealthStatus{std::string deviceId,status,message; double driftScore=0; int daysToCalibration=0;}; class CalibrationMonitor{public: void updateDrift(const std::string&,double); HealthStatus status(const std::string&) const; private: std::map<std::string,double> m_drift;};}

#include "Database.h"
#include <filesystem>
#include <fstream>
namespace ashkan::database {
Database::Database(std::string folder):m_folder(std::move(folder)){}
bool Database::initialize(){ std::filesystem::create_directories(m_folder); std::ofstream(m_folder+"/readings.csv",std::ios::app); std::ofstream(m_folder+"/alarms.csv",std::ios::app); return true; }
void Database::insertReading(const AnalyzerReading& r){ std::lock_guard<std::mutex> l(m_mutex); std::ofstream f(m_folder+"/readings.csv",std::ios::app); f<<r.timestamp<<","<<r.deviceId<<","<<r.parameter<<","<<r.value<<","<<r.status<<"\n"; }
void Database::insertAlarm(const ashkan::alerts::AlarmEvent& e){ std::lock_guard<std::mutex> l(m_mutex); std::ofstream f(m_folder+"/alarms.csv",std::ios::app); f<<e.timestamp<<","<<e.deviceId<<","<<e.parameter<<","<<e.value<<","<<ashkan::alerts::toString(e.level)<<","<<e.acknowledged<<","<<e.message<<"\n"; }
std::string Database::folder() const{return m_folder;}
}

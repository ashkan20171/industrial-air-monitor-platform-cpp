#pragma once
#include <mutex>
#include <string>
#include "../core/AnalyzerReading.h"
#include "../alerts/AlarmEngine.h"
namespace ashkan::database {
class Database {
public:
    explicit Database(std::string folder = "data");
    bool initialize();
    void insertReading(const AnalyzerReading& r);
    void insertAlarm(const ashkan::alerts::AlarmEvent& e);
    std::string folder() const;
private:
    std::string m_folder; mutable std::mutex m_mutex;
};
}

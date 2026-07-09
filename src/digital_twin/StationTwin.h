#pragma once
#include <string>
#include <map>

namespace digital_twin {

class StationTwin {
public:
    explicit StationTwin(std::string stationId);
    void setProperty(const std::string& key, const std::string& value);
    std::string getProperty(const std::string& key) const;
    std::string stationId() const;
private:
    std::string stationId_;
    std::map<std::string, std::string> properties_;
};

}

#include "StationTwin.h"

namespace digital_twin {

StationTwin::StationTwin(std::string stationId) : stationId_(std::move(stationId)) {}
void StationTwin::setProperty(const std::string& key, const std::string& value) { properties_[key] = value; }
std::string StationTwin::getProperty(const std::string& key) const {
    auto it = properties_.find(key);
    return it == properties_.end() ? std::string{} : it->second;
}
std::string StationTwin::stationId() const { return stationId_; }

}

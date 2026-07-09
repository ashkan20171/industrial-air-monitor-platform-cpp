#pragma once
#include <string>
#include <vector>
namespace ashkan::discovery {
struct DiscoveredDevice { std::string id, brand, model, protocol, address; int confidence=0; };
class DeviceScanner { public: std::vector<DiscoveredDevice> scanSerial(); std::vector<DiscoveredDevice> scanModbusTcp(const std::string& subnetPrefix="192.168.1.", int from=1, int to=254); };
}

#include "DeviceScanner.h"
#ifdef _WIN32
#include <windows.h>
#endif
namespace ashkan::discovery {
std::vector<DiscoveredDevice> DeviceScanner::scanSerial(){ std::vector<DiscoveredDevice> out; for(int i=1;i<=32;i++){ out.push_back({"COM"+std::to_string(i),"UNKNOWN","AutoProbe","SERIAL","COM"+std::to_string(i),20}); } return out; }
std::vector<DiscoveredDevice> DeviceScanner::scanModbusTcp(const std::string& p,int f,int t){ std::vector<DiscoveredDevice> out; for(int i=f;i<=t && i<f+8;i++) out.push_back({"TCP-"+std::to_string(i),"UNKNOWN","ModbusProbe","MODBUS_TCP",p+std::to_string(i)+":502",10}); return out; }
}

#pragma once
#include <string>
namespace ashkan::integration { class OPCBridge{public: virtual ~OPCBridge()=default; virtual bool publishTag(const std::string& tag,double value){(void)tag;(void)value;return false;} }; }

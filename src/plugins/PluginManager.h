#pragma once
#include <string>
#include <vector>

namespace plugins {

class PluginManager {
public:
    bool loadDriverPlugin(const std::string& path);
    std::vector<std::string> loadedPlugins() const;
private:
    std::vector<std::string> plugins_;
};

}

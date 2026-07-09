#include "PluginManager.h"

namespace plugins {

bool PluginManager::loadDriverPlugin(const std::string& path) {
    // Production implementation: use QLibrary or platform dynamic loader.
    plugins_.push_back(path);
    return true;
}

std::vector<std::string> PluginManager::loadedPlugins() const { return plugins_; }

}

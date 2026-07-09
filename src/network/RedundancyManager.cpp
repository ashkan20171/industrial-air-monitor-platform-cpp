#include "RedundancyManager.h"

namespace network {

void RedundancyManager::setRole(NodeRole role) { role_ = role; }
NodeRole RedundancyManager::role() const { return role_; }
bool RedundancyManager::shouldAcceptWrites() const { return role_ == NodeRole::Primary; }

}

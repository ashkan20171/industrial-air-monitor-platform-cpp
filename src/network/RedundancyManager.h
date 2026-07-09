#pragma once
#include <string>

namespace network {

enum class NodeRole { Primary, Secondary, Observer };

class RedundancyManager {
public:
    void setRole(NodeRole role);
    NodeRole role() const;
    bool shouldAcceptWrites() const;
private:
    NodeRole role_ = NodeRole::Primary;
};

}

#pragma once
#include <string>
#include <set>
#include <map>

namespace security {

enum class Role { Admin, Engineer, Operator, Viewer };

enum class Permission {
    ViewDashboard,
    AcknowledgeAlarm,
    ChangeConfiguration,
    ManageUsers,
    ExportReports,
    CalibrateDevice
};

class RBAC {
public:
    RBAC();
    bool hasPermission(Role role, Permission permission) const;
private:
    std::map<Role, std::set<Permission>> matrix_;
};

}

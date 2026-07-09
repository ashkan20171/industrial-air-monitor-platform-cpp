#include "RBAC.h"

namespace security {

RBAC::RBAC() {
    matrix_[Role::Admin] = {
        Permission::ViewDashboard,
        Permission::AcknowledgeAlarm,
        Permission::ChangeConfiguration,
        Permission::ManageUsers,
        Permission::ExportReports,
        Permission::CalibrateDevice
    };
    matrix_[Role::Engineer] = {
        Permission::ViewDashboard,
        Permission::AcknowledgeAlarm,
        Permission::ChangeConfiguration,
        Permission::ExportReports,
        Permission::CalibrateDevice
    };
    matrix_[Role::Operator] = {
        Permission::ViewDashboard,
        Permission::AcknowledgeAlarm,
        Permission::ExportReports
    };
    matrix_[Role::Viewer] = {
        Permission::ViewDashboard
    };
}

bool RBAC::hasPermission(Role role, Permission permission) const {
    auto it = matrix_.find(role);
    if (it == matrix_.end()) return false;
    return it->second.count(permission) > 0;
}

}

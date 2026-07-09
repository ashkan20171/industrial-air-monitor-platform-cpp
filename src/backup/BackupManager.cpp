#include "BackupManager.h"

namespace backup {

bool BackupManager::createBackup(const std::string& targetPath) {
    lastBackup_ = targetPath;
    // Production: snapshot DB, configs, audit logs, reports.
    return true;
}

bool BackupManager::restoreBackup(const std::string&) {
    // Production: validate checksum, restore DB/configs, run smoke tests.
    return true;
}

std::string BackupManager::lastBackupPath() const { return lastBackup_; }

}

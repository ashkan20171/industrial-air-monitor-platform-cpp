#pragma once
#include <string>

namespace backup {

class BackupManager {
public:
    bool createBackup(const std::string& targetPath);
    bool restoreBackup(const std::string& backupPath);
    std::string lastBackupPath() const;
private:
    std::string lastBackup_;
};

}

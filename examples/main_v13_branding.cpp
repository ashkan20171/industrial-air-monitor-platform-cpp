#include <iostream>
#include "../src/observability/MetricsRegistry.h"
#include "../src/digital_twin/StationTwin.h"
#include "../src/backup/BackupManager.h"

int main() {
    std::cout << "Ashkan AI Air Monitor V13" << std::endl;
    std::cout << "Programmer: Ashkan Motaei" << std::endl;

    observability::MetricsRegistry metrics;
    metrics.increment("readings_total");
    metrics.setGauge("station_health", 1.0);

    digital_twin::StationTwin station("station-001");
    station.setProperty("location", "Industrial Site");
    station.setProperty("owner", "Ashkan Motaei");

    backup::BackupManager backup;
    backup.createBackup("backups/station-001.snapshot");

    std::cout << "Station: " << station.stationId() << std::endl;
    std::cout << "Readings total: " << metrics.get("readings_total") << std::endl;
    std::cout << "Backup: " << backup.lastBackupPath() << std::endl;
    return 0;
}

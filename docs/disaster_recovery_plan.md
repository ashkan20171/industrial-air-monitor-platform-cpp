# Disaster Recovery Plan

## Recovery Objectives

| Item | Target |
|---|---|
| RPO | 15 minutes for critical station data |
| RTO | 2 hours for station-level recovery |
| Backup Frequency | Daily full backup + frequent incremental backup |
| Critical Data | Measurements, alarms, users, configs, reports |

## Backup Strategy
- Local rolling backups
- External storage replication
- Encrypted configuration backup
- Database export snapshots
- Report archive backup

## Recovery Steps
1. Stop affected services.
2. Verify latest valid backup.
3. Restore configuration and database.
4. Validate system integrity.
5. Run smoke tests.
6. Confirm analyzer connectivity.
7. Resume telemetry and reporting.
8. Record recovery event in audit trail.

# Industrial Threat Model

## Assets
- Analyzer measurements
- Calibration records
- Alarm records
- User accounts and permissions
- Configuration files
- Reports and exported data
- OPC-UA and MQTT endpoints

## Threats

| Threat | Impact | Mitigation |
|---|---|---|
| Unauthorized configuration change | Invalid measurements or unsafe operation | RBAC, audit trail, approval workflow |
| MQTT topic spoofing | False telemetry | TLS, client certificates, broker ACL |
| OPC-UA unauthorized access | SCADA data exposure | OPC-UA security policies, certificates |
| Device communication tampering | False readings | Network segmentation, signed config, validation |
| Data loss | Compliance failure | Local buffering, backup/restore, replication |
| Weak passwords | Account compromise | Password policy, MFA plan, lockout |
| Supply-chain dependency issue | Build compromise | SBOM, dependency pinning, CI scanning |

## Security Principles
- Least privilege
- Defense in depth
- Network segmentation
- Secure defaults
- Auditability
- Traceability
- Fail-safe behavior

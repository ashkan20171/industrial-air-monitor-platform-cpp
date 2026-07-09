# Factory Acceptance Test — FAT Template

## Project
Ashkan AI Air Monitor V12 EU Industrial Enterprise Platform

## Test Categories

| ID | Test Area | Description | Expected Result | Status |
|---|---|---|---|---|
| FAT-001 | Startup | Application starts without crash | System online | Pending |
| FAT-002 | Device Driver | Simulated analyzer produces readings | Valid data received | Pending |
| FAT-003 | Alarm Engine | High pollutant value triggers alarm | Alarm generated | Pending |
| FAT-004 | Acknowledgement | Operator acknowledges alarm | Audit record created | Pending |
| FAT-005 | OPC-UA | SCADA client reads nodes | Data available | Pending |
| FAT-006 | MQTT | Telemetry published to topic | Broker receives payload | Pending |
| FAT-007 | Database | Readings stored locally | Query returns records | Pending |
| FAT-008 | Report | Daily report generated | PDF/CSV output | Pending |
| FAT-009 | RBAC | Viewer cannot change config | Access denied | Pending |
| FAT-010 | Audit Trail | Config change is logged | Event trace exists | Pending |

## Acceptance Criteria
All critical tests must pass before site deployment.

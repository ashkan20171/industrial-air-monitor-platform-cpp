# V12 Architecture Map

```text
src/
├── core/              Domain models and readings
├── drivers/           Analyzer-specific drivers
├── protocols/         Serial, TCP, Modbus framing
├── pipeline/          Data ingestion and processing
├── alerts/            Alarm lifecycle and escalation
├── database/          Local persistence
├── discovery/         Auto device discovery
├── web/               REST/WebSocket dashboard services
├── integration/
│   ├── opcua/         SCADA/OPC-UA interface
│   └── mqtt/          IoT/cloud telemetry interface
├── reporting/         PDF/Excel/CSV reporting abstraction
├── security/          RBAC and audit trail
├── compliance/        EU/EPA style validation logic
├── ai/ml/             Anomaly detection and drift concepts
├── network/           Redundancy and multi-station concepts
└── plugins/           Dynamic driver plugin loading
```

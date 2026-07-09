# EU Industrial Software Interview Talking Points

## 1. Architecture
Explain that the system is layered:

- Device drivers
- Protocol adapters
- Data pipeline
- Alarm engine
- Persistence layer
- Integration layer
- Web/API layer
- AI/analytics layer
- Reporting layer
- Security/audit layer

## 2. Why OPC-UA?
OPC-UA is widely used for secure, structured industrial data exchange with SCADA, HMI, MES, and historian systems.

## 3. Why MQTT?
MQTT is lightweight and useful for cloud/edge telemetry, multi-station communication, and IoT dashboards.

## 4. Alarm Philosophy
The alarm engine supports severity levels, acknowledgement, lifecycle tracking, and escalation concepts.

## 5. Reliability
Discuss retry logic, offline buffering, local database persistence, watchdog concepts, and redundant deployment.

## 6. Cybersecurity
Mention RBAC, audit logs, secure configuration, network segmentation, and future TLS/certificate support.

## 7. AI Usage
AI is used as an assistant layer, not as a replacement for validated measurements. It supports anomaly detection, drift prediction, and maintenance scoring.

## 8. What You Would Improve in Production
- Real device protocol validation using vendor manuals
- TLS certificates for OPC-UA/MQTT
- PostgreSQL/TimescaleDB for large deployments
- Hardware-in-the-loop testing
- Formal FAT/SAT documents
- IEC 62443 aligned threat model

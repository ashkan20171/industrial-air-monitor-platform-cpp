# Industrial Air Monitor Platform — C++/Qt Edition

[![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-blue)](#)
[![Qt](https://img.shields.io/badge/Qt-6.x-41CD52)](#)
[![Architecture](https://img.shields.io/badge/Architecture-Industrial%20Enterprise-orange)](#)
[![Domain](https://img.shields.io/badge/Domain-IIoT%20%7C%20SCADA-informational)](#)

Enterprise-grade industrial air monitoring platform built with **C++** and **Qt** for **SCADA-connected**, **IoT-enabled**, and **AI-assisted** environmental monitoring systems.

This project demonstrates how to design a modular industrial software platform that integrates **analyzer drivers**, **serial/TCP/Modbus communication**, **OPC-UA**, **MQTT telemetry**, **alarm management**, **real-time data pipelines**, **RBAC**, **audit logging**, **compliance-oriented architecture**, and **edge deployment readiness**.

---

## Why this project stands out

This is not a simple desktop app.

It is a portfolio-grade **industrial software platform** designed around patterns used in real-world monitoring, automation, telemetry, and enterprise integration systems.

### It demonstrates:
- Industrial device integration and protocol abstraction
- Modular architecture for large-scale maintainable systems
- Real-time telemetry ingestion and processing
- SCADA and enterprise interoperability
- Security-aware design with auditability and access control
- AI-assisted anomaly detection for operational monitoring
- Deployment thinking across desktop, edge, Docker, and Kubernetes

---

## Business / Industrial Use Cases

This platform is suitable for scenarios such as:

- Industrial air quality monitoring stations
- Factory environmental monitoring systems
- Smart city environmental telemetry
- Edge gateways for pollutant analyzers
- SCADA/HMI-connected analyzer networks
- Compliance-oriented monitoring dashboards
- Industrial software engineering portfolio demonstration

---

## Core Capabilities

### 1) Industrial Device Connectivity
Supports analyzer-oriented communication patterns through:
- Serial communication
- TCP/IP communication
- Modbus-based integration
- Vendor-specific driver abstraction

Implemented driver structure includes components for:
- BAM analyzers
- Ecotech analyzers
- Horiba analyzers
- ESA analyzers
- Generic ASCII devices

---

### 2) Real-Time Data Pipeline
The platform contains a dedicated processing pipeline for:
- collecting analyzer readings
- normalizing device output
- validating measurements
- forwarding telemetry
- persisting operational data

This reflects the design of a real industrial ingestion layer rather than a simple UI-driven application.

---

### 3) SCADA and Enterprise Integration
The project includes enterprise-facing integration building blocks such as:
- **OPC-UA server** skeleton for SCADA/HMI integration
- **MQTT client bridge** for telemetry publishing
- REST and WebSocket interfaces for external consumers
- extensible integration points for higher-level systems

This is especially important for recruiters looking for engineers with **OT/IT bridging** experience.

---

### 4) AI-Assisted Monitoring
The platform includes AI/ML-oriented modules for:
- anomaly detection
- abnormal trend spotting
- predictive maintenance direction
- intelligent monitoring workflows

This makes the project stronger than a standard monitoring application because it connects **industrial software engineering** with **practical AI usage**.

---

### 5) Security and Compliance Awareness
The architecture also reflects enterprise and industrial security concerns:
- Role-Based Access Control (**RBAC**)
- Audit trail / audit logging
- cybersecurity-oriented design thinking
- compliance and reporting modules
- threat-model and industrial documentation support

These are strong signals for recruiters in industrial, enterprise, and regulated environments.

---

## Architecture Overview

The repository is organized into domain-oriented modules:
```text
src/
├── ai/                 # AI engine and ML-related processing
├── alerts/             # Alarm lifecycle and alert handling
├── backup/             # Backup and recovery support
├── compliance/         # Compliance-oriented validation/reporting concepts
├── core/               # Shared domain models and configuration
├── database/           # Persistence layer
├── digital_twin/       # Digital twin concepts for monitoring assets
├── discovery/          # Device scanning and discovery
├── drivers/            # Analyzer driver abstractions and implementations
├── edge/               # Edge gateway concepts
├── integration/        # MQTT / OPC-UA and enterprise connectivity
├── maintenance/        # Calibration and maintenance monitoring
├── network/            # Redundancy and network-related support
├── observability/      # Health checks and metrics
├── pipeline/           # Real-time data pipeline
├── plugins/            # Extensibility points
├── protocols/          # Serial / TCP / Modbus communication
├── reporting/          # Reporting abstractions
├── security/           # RBAC and audit trail
├── simulator/          # Analyzer simulation support
├── ui/                 # Qt UI components
└── web/                # REST and WebSocket interfaces

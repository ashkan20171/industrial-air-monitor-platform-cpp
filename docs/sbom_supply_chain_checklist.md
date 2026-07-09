# SBOM and Supply Chain Security Checklist

## Software Bill of Materials Plan
- C++ compiler and standard library version
- Qt version
- CMake version
- OPC-UA library version, e.g. open62541
- MQTT library version, e.g. Eclipse Paho or Qt MQTT
- Database library version
- Container base image digest

## Supply Chain Security
- [ ] Pin dependency versions
- [ ] Review licenses
- [ ] Generate SBOM during CI
- [ ] Scan container image
- [ ] Avoid hardcoded secrets
- [ ] Sign release artifacts
- [ ] Keep third-party libraries updated

# Deployment

## Docker
```bash
docker compose up --build
```

## Kubernetes
```bash
kubectl apply -f deployment/kubernetes/airmonitor-deployment.yaml
```

## Production Notes
- Configure TLS for OPC-UA and MQTT.
- Use persistent volumes for database and reports.
- Use secrets management for passwords and certificates.
- Place the system inside a segmented OT/DMZ network.

# SLA / SLO Template

## Service Level Objectives

| Metric | Target |
|---|---|
| Platform availability | 99.5% monthly |
| Data ingestion latency | < 5 seconds typical |
| Alarm generation latency | < 2 seconds after validated reading |
| Dashboard response time | < 1 second for normal views |
| MQTT publish success | > 99% when broker reachable |
| Local data retention | Configurable, default 12 months |

## Error Budget
If availability drops below target, focus shifts from feature development to reliability improvement.

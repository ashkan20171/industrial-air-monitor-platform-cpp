# Ashkan AI Air Monitor V11 Industrial Platform

این نسخه روی V10 Driver Suite ساخته شده و یک پلتفرم صنعتی کامل‌تر فراهم می‌کند.

## ماژول‌های اضافه‌شده
- `pipeline`: مسیر مرکزی داده برای اتصال Driverها به DB/Alarm/AI/Web
- `alerts`: موتور آلارم چندسطحی با history و acknowledge
- `ai`: تشخیص Spike، Drift و Flat-line با Moving Window و Z-Score
- `database`: ذخیره‌سازی runtime به‌صورت CSV سبک و قابل تبدیل به SQLite/PostgreSQL
- `discovery`: اسکلت اسکن COM و Modbus TCP برای Auto Discovery
- `maintenance`: Health و Calibration Monitor
- `web`: REST/WebSocket stub آماده اتصال به QtHttpServer/Boost.Beast
- `integration`: آماده‌سازی OPC-UA/SCADA bridge

## مثال اجرا
فایل نمونه:

```text
examples/main_v11_platform.cpp
```

## مسیر ارتقاء بعدی
برای محیط production پیشنهاد می‌شود:
1. جایگزینی `database` با SQLite واقعی یا PostgreSQL.
2. اتصال `RestServer` به QtHttpServer یا Boost.Beast.
3. اتصال `OPCBridge` به open62541.
4. تکمیل Probe واقعی در `DeviceScanner` برای هر برند.

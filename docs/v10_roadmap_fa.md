# نقشه راه V10

## پیاده‌سازی‌شده در این مرحله

### 1) Ecotech
- درایور اختصاصی `EcotechDriver`
- فرمان polling قابل تنظیم
- ساختار تحلیل O3 و Status

### 2) BAM
- درایور اختصاصی `BAMDriver`
- تحلیل PM2.5 و سطوح هشدار

### 3) Horiba
- درایور اختصاصی `HoribaDriver`
- الگوی خواندن NOx / NO2 / NO

### 4) Modbus Base
- ساخت فریم RTU
- قابلیت poll رجیسترها
- آماده برای map اختصاصی هر برند

### 5) Settings Panel
- انتخاب برند
- نوع اتصال
- پورت / endpoint
- baud rate
- poll command

### 6) Simulator
- تولید داده تست بدون سخت‌افزار
- مناسب برای توسعه UI، Database و Alerts

## برای تکمیل نهایی هر برند
باید این موارد اضافه شود:
- parser اختصاصی همان مدل
- register map واقعی
- unit conversion
- alarm/status decoder
- reconnect logic

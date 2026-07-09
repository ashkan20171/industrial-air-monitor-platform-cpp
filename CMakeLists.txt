cmake_minimum_required(VERSION 3.16)
project(AshkanAirMonitorV10DriverSuite LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets SerialPort Network)

add_executable(ashkan_driver_suite
    examples/main.cpp
    src/core/AnalyzerReading.cpp
    src/core/AnalyzerConfig.cpp
    src/drivers/IAnalyzerDriver.cpp
    src/drivers/AnalyzerFactory.cpp
    src/drivers/EcotechDriver.cpp
    src/drivers/BAMDriver.cpp
    src/drivers/HoribaDriver.cpp
    src/drivers/ESADriver.cpp
    src/drivers/GenericAsciiDriver.cpp
    src/drivers/ModbusAnalyzerDriver.cpp
    src/protocols/SerialClient.cpp
    src/protocols/TcpClient.cpp
    src/protocols/ModbusFrame.cpp
    src/ui/SettingsWindow.cpp
    src/simulator/AnalyzerSimulator.cpp
)

target_include_directories(ashkan_driver_suite PRIVATE src)

target_link_libraries(ashkan_driver_suite PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::SerialPort
    Qt6::Network
)


# V11 Industrial Platform modules
set(V11_PLATFORM_SOURCES
    src/pipeline/DataPipeline.cpp
    src/alerts/AlarmEngine.cpp
    src/ai/AIEngine.cpp
    src/database/Database.cpp
    src/discovery/DeviceScanner.cpp
    src/maintenance/CalibrationMonitor.cpp
    src/web/RestServer.cpp
    src/web/WebSocketServer.cpp
)

add_executable(ashkan_v11_platform_demo
    examples/main_v11_platform.cpp
    ${V11_PLATFORM_SOURCES}
    src/core/AnalyzerReading.cpp
)

target_include_directories(ashkan_v11_platform_demo PRIVATE src)

# V12 modules added: security, reporting, compliance, opcua, mqtt, ai/ml, network, plugins

# V13 modules added by Ashkan Motaei branding edition: observability, backup, digital_twin, edge, deployment assets

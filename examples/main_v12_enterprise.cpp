#include <iostream>
#include "../src/security/RBAC.h"
#include "../src/security/AuditTrail.h"
#include "../src/integration/mqtt/MQTTClient.h"
#include "../src/integration/opcua/OPCUAServer.h"
#include "../src/ai/ml/AnomalyDetector.h"

int main() {
    security::RBAC rbac;
    std::cout << "Admin can manage users: "
              << rbac.hasPermission(security::Role::Admin, security::Permission::ManageUsers)
              << std::endl;

    integration::OPCUAServer opcua;
    opcua.start(4840);

    integration::MQTTClient mqtt;
    mqtt.connect("localhost", 1883, "ashkan-v12");
    mqtt.publish("airmonitor/station-001/status", "{\"status\":\"online\"}");

    ai::ml::AnomalyDetector detector;
    detector.train({10, 11, 9, 10.5, 10.2});
    std::cout << "Anomaly score: " << detector.anomalyScore(25) << std::endl;

    std::cout << "V12 Enterprise platform skeleton is running." << std::endl;
    return 0;
}

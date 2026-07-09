#pragma once
#include <string>
#include <vector>

namespace reporting {

struct ReportRequest {
    std::string stationId;
    std::string fromUtc;
    std::string toUtc;
    std::string format; // pdf, xlsx, csv
};

class ReportGenerator {
public:
    std::string generateDailyComplianceReport(const ReportRequest& request);
    std::string generateAlarmSummaryReport(const ReportRequest& request);
    std::string generateMaintenanceReport(const ReportRequest& request);
};

}

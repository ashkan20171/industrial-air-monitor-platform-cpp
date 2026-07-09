#include "ReportGenerator.h"
#include <sstream>

namespace reporting {

std::string ReportGenerator::generateDailyComplianceReport(const ReportRequest& request) {
    std::ostringstream out;
    out << "reports/" << request.stationId << "_daily_compliance." << request.format;
    return out.str();
}

std::string ReportGenerator::generateAlarmSummaryReport(const ReportRequest& request) {
    std::ostringstream out;
    out << "reports/" << request.stationId << "_alarm_summary." << request.format;
    return out.str();
}

std::string ReportGenerator::generateMaintenanceReport(const ReportRequest& request) {
    std::ostringstream out;
    out << "reports/" << request.stationId << "_maintenance." << request.format;
    return out.str();
}

}

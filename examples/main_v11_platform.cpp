#include <iostream>
#include "../src/pipeline/DataPipeline.h"
#include "../src/alerts/AlarmEngine.h"
#include "../src/ai/AIEngine.h"
#include "../src/database/Database.h"
#include "../src/web/RestServer.h"

int main(){
    using namespace ashkan;
    pipeline::DataPipeline pipe;
    alerts::AlarmEngine alarms;
    ai::AIEngine ai;
    database::Database db("data/v11_runtime"); db.initialize();
    web::RestServer rest(8080); rest.start();

    alarms.addRule({"STATION-01","PM2.5",35,75,150,2,true});
    alarms.subscribe([&](const alerts::AlarmEvent& e){ db.insertAlarm(e); std::cout << "ALARM: " << e.message << std::endl; });
    pipe.subscribe("database", [&](const AnalyzerReading& r){ db.insertReading(r); });
    pipe.subscribe("alarms", [&](const AnalyzerReading& r){ alarms.onReading(r); });
    pipe.subscribe("ai", [&](const AnalyzerReading& r){ for(auto& e: ai.onReading(r)) std::cout << "AI: " << e.message << std::endl; });

    for(int i=0;i<50;i++){
        AnalyzerReading r; r.timestamp="2026-06-05T12:00:"+std::to_string(i); r.deviceId="STATION-01"; r.parameter="PM2.5"; r.value=(i==25?180:20+i*0.3); r.status="OK";
        pipe.pushReading(r);
    }
    std::cout << rest.statusJson() << std::endl;
    return 0;
}

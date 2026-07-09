#include <QApplication>
#include <QDebug>
#include "ui/SettingsWindow.h"
#include "simulator/AnalyzerSimulator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    AnalyzerSimulator sim;
    AnalyzerReading r = sim.simulate("Ecotech", "Virtual-1");
    qInfo() << "Simulator raw:" << r.rawFrame;

    SettingsWindow w;
    w.show();
    return app.exec();
}

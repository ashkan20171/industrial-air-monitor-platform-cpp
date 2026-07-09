#include "SettingsWindow.h"
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDateTime>

SettingsWindow::SettingsWindow(QWidget* parent): QWidget(parent) {
    vendorBox = new QComboBox; vendorBox->addItems({"Ecotech","BAM","Horiba","ESA","Generic"});
    connectionBox = new QComboBox; connectionBox->addItems({"serial","modbus_rtu","tcp","simulator"});
    endpointEdit = new QLineEdit("COM3");
    baudEdit = new QLineEdit("9600");
    commandEdit = new QLineEdit("DATA?\\r\\n");
    logBox = new QTextEdit; logBox->setReadOnly(true);
    testBtn = new QPushButton("Test Configuration");

    auto* form = new QFormLayout;
    form->addRow("Vendor:", vendorBox);
    form->addRow("Connection:", connectionBox);
    form->addRow("Endpoint:", endpointEdit);
    form->addRow("Baud:", baudEdit);
    form->addRow("Poll Command:", commandEdit);

    auto* layout = new QVBoxLayout(this);
    layout->addLayout(form);
    layout->addWidget(testBtn);
    layout->addWidget(logBox);

    connect(testBtn, &QPushButton::clicked, this, &SettingsWindow::onTestClicked);
    setWindowTitle("Analyzer Settings Panel");
    resize(520, 420);
}

void SettingsWindow::onTestClicked() {
    logBox->append("[" + QDateTime::currentDateTime().toString() + "] Vendor=" + vendorBox->currentText() +
                   ", Connection=" + connectionBox->currentText() +
                   ", Endpoint=" + endpointEdit->text() +
                   ", Baud=" + baudEdit->text() +
                   ", Command=" + commandEdit->text());
}

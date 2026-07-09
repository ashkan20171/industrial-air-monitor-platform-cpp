#pragma once
#include <QWidget>
class QComboBox; class QLineEdit; class QPushButton; class QTextEdit;
class SettingsWindow : public QWidget {
    Q_OBJECT
public:
    explicit SettingsWindow(QWidget* parent=nullptr);
private slots:
    void onTestClicked();
private:
    QComboBox* vendorBox;
    QComboBox* connectionBox;
    QLineEdit* endpointEdit;
    QLineEdit* baudEdit;
    QLineEdit* commandEdit;
    QTextEdit* logBox;
    QPushButton* testBtn;
};

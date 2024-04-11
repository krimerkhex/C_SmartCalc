#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "calculator.h"
#include "credit.h"
#include "depozit.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void show_another_window();

    void on_actionCalculator_triggered();

    void on_actionCredit_triggered();

    void on_actionDepozit_triggered();

    void on_actionExit_triggered();
private:
    Ui::MainWindow *ui;
    // Привязываем остальные окна к данному
    calculator *calc_window;
    credit *credit_window;
    depozit *depozit_window;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {
    ui->setupUi(this);

}

MainWindow::~MainWindow() {
    delete ui;
}

int flag = 0;

void MainWindow::show_another_window() {
    switch (flag) {
    case 1:
        disconnect(calc_window, &calculator::deletevald, this, &MainWindow::show);
        calc_window->~calculator(); // 1 способ очистки
//        delete calc_window; // 2 способ очистки
        break;
    case 2:
        disconnect(credit_window, &credit::deletevald, this, &MainWindow::show);
        credit_window->~credit(); // 1 способ очистки
//        delete credit_window; // 2 способ очистки
        break;
    case 3:
        disconnect(depozit_window, &depozit::deletevald, this, &MainWindow::show);
        depozit_window->~depozit(); // 1 способ очистки
//        delete depozit_window; // 2 способ очистки
        break;
    default:
        break;
    }
}

void MainWindow::on_actionCalculator_triggered()
{
    show_another_window();
    calc_window = new calculator();
    connect(calc_window, &calculator::showWindow, this, &MainWindow::show);
    flag = 1;
    ui->statusbar->showMessage("Обычный калькулятор\n");
    setCentralWidget(calc_window);
}



void MainWindow::on_actionCredit_triggered()
{
    show_another_window();
    credit_window = new credit();
    connect(credit_window, &credit::showWindow, this, &MainWindow::show);
    flag = 2;
    ui->statusbar->showMessage("Кредитный калькулятор\n");
    setCentralWidget(credit_window);
}


void MainWindow::on_actionDepozit_triggered()
{
    show_another_window();
    depozit_window = new depozit();
    connect(depozit_window, &depozit::showWindow, this, &MainWindow::show);
    flag = 3;
    ui->statusbar->showMessage("Депозитный калькулятор\n");
    setCentralWidget(depozit_window);
}


void MainWindow::on_actionExit_triggered()
{
    show_another_window();
    QApplication::quit();
}

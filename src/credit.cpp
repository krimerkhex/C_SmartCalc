#include "credit.h"
#include "ui_credit.h"

credit::credit(QWidget *parent) : QWidget(parent), ui(new Ui::credit) {
    ui->setupUi(this);
    ui->sum_credit->setValidator(val_double_1);
    ui->procent->setValidator(val_double_1);
    ui->time->setValidator(val_double_3);
    ui->give_date->setValidator(val_double_4);
}

credit::~credit() {
    delete val_double_1;
    delete val_double_3;
    delete val_double_4;
    delete ui;
}

void credit::inicilization(to_brains_credit *strct) {
    strct->sum_credit = ui->sum_credit->text().toDouble();
    strct->procent = ui->procent->text().toDouble();
    strct->time = ui->comboBox_2->currentIndex() == 0 ? (int)ui->time->text().toDouble() * 12 : (int)ui->time->text().toDouble();
    std::string data_open = ui->give_date->text().toUtf8().constData();
    strct->year = atoi(data_open.substr(0, 4).c_str());
    strct->mouth = atoi(data_open.substr(5, 2).c_str());
    strct->day = atoi(data_open.substr(8, 2).c_str());
    strct->repay_proc = ui->comboBox_3->currentIndex();
    strct->all_gived = 0.0;
    strct->gived_more = 0.0;
    strct->status_error = (strct->sum_credit == 0.0 || strct->sum_credit == 0 ||
                           strct->procent == 0.0 || strct-> procent == 0 ||
                           strct->time == 0 || strct->year == 0000 || strct->mouth == 00 ||
                           strct->day == 00) ? 1 : 0;
}
void credit::on_pushButton_clicked() {
    ui->sum_per_mouth->setText("");
    to_brains_credit credit;
    inicilization(&credit);
    distributio(&credit);
    if (!credit.status_error) {
        ui->all_gived->setText(QString::number(credit.all_gived,'f', 2));
        ui->gived_more->setText(QString::number(credit.gived_more,'f', 2));
        if (credit.repay_proc == 0) {
            ui->sum_per_mouth->setText(QString::number((int)credit.sum_per_mouth[0], 'f', 2) + "\n");;
        } else  if (credit.repay_proc == 1){
            for (int i = 0; i < credit.time; i++) {
                ui->sum_per_mouth->setText(ui->sum_per_mouth->toPlainText() + QString::number((int)credit.sum_per_mouth[i], 'f', 2) + "\n");
            }
        }
    } else {
        QMessageBox::critical(this, "ERROR", "Data valid error");
        // Все поля чистятся
        ui->sum_credit->setText("0.0");
        ui->procent->setText("0.0");
        ui->time->setText("0.0");
        ui->give_date->setText("0000:00:00");
    }
}

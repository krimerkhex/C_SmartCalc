#include "depozit.h"
#include "ui_depozit.h"
#include <iostream>

depozit::depozit(QWidget *parent) : QWidget(parent), ui(new Ui::depozit) {
    ui->setupUi(this);
    // Поля связанные с деньгами
    ui->contribution->setValidator(val_double_1);
    ui->add->setValidator(val_double_1);
    ui->sub->setValidator(val_double_1);

    // Поля связанные с процентами
    ui->tax->setValidator(val_double_3);
    ui->procent->setValidator(val_double_3);

    // Поля связанные со временем
    ui->time->setValidator(val_double_3);
    ui->date_open->setValidator(val_double_4);
    ui->sub_time->setValidator(val_double_4);
    ui->add_time->setValidator(val_double_4);
}

depozit::~depozit() {
    delete val_double_1;
    delete val_double_3;
    delete val_double_4;
    delete ui;
}

void depozit::inicilization(to_brains_depozit *strct) {
    strct->sum_contr = ui->contribution->text().toDouble();
    strct->procent = ui->procent->text().toDouble();
    strct->time = ui->comboBox_3->currentIndex() == 1 ? (int)ui->time->text().toDouble() * 12 : (int)ui->time->text().toDouble();
    strct->year = atoi(ui->date_open->text().toStdString().substr(0, 4).c_str());
    strct->mouth = atoi(ui->date_open->text().toStdString().substr(5, 2).c_str());
    strct->day = atoi(ui->date_open->text().toStdString().substr(8, 2).c_str());
    strct->tax = ui->tax->text().toDouble();
    strct->payment_per = ui->payment_per->currentIndex();
    strct->payment_flag = ui->payment_flag->currentIndex();

    strct->sum_add = ui->add->text().toDouble();
    strct->sum_sub = ui->sub->text().toDouble();

    std::string time = ui->add_time->text().toStdString();
    strct->add_year = atoi(time.substr(0, 4).c_str());
    strct->add_mouth = atoi(time.substr(5, 2).c_str());
    strct->add_day = atoi(time.substr(8, 2).c_str());
    time.clear();
    time = ui->sub_time->text().toStdString();
    strct->sub_year = atoi(time.substr(0, 4).c_str());
    strct->sub_mouth = atoi(time.substr(5, 2).c_str());
    strct->sub_day = atoi(time.substr(8, 2).c_str());
    strct->status_error = (strct->sum_contr == 0 || strct->sum_contr == 0.0 ||
                           strct->procent == 0 || strct->procent == 0.0 ||
                           strct->time == 0 || strct->tax == 0 || strct->tax == 0.0 ||
                           strct->year == 0000 || strct->mouth == 00 || strct->day == 00) ? 1 : 0;
    time.clear();
}

void depozit::on_run_clicked() {
    to_brains_depozit depozit;
    inicilization(&depozit);
    distribut(&depozit); // Отправка в Мозги
    // Вывод данных в QListEdit
    if (!depozit.status_error) {
        std::cout<<depozit.sum_end<<std::endl;
        std::cout<<depozit.sum_tax<<std::endl;
        std::cout<<depozit.sum_procent<<std::endl;
        ui->sum_end->setText("");
        ui->sum_tax->setText("");
        ui->sum_procent->setText("");
        ui->sum_end->setText(QString::number(depozit.sum_end, 'f', 2));
        ui->sum_tax->setText(QString::number(depozit.sum_tax, 'f', 2));
        ui->sum_procent->setText(QString::number(depozit.sum_procent, 'f', 2));
    } else {
        QMessageBox::critical(this, "ERROR", "Data valid error");
        // Все поля чистятся
        ui->contribution->setText("0.0");
        ui->procent->setText("0.0");
        ui->date_open->setText("0000:00:00");
        ui->tax->setText("0.0");
    }
}

bool depozit::check(std::string time) {
    bool flag = true;
    std::string data_open = ui->date_open->text().toStdString();
    int year_1 = atoi(data_open.substr(0, 4).c_str()), year_2 = atoi(time.substr(0, 4).c_str());
    int mouth_1 = atoi(data_open.substr(5, 2).c_str()), mouth_2 = atoi(time.substr(5, 2).c_str());
    int day_1 = atoi(data_open.substr(8, 2).c_str()), day_2 = atoi(time.substr(8, 2).c_str());
    if (year_1 == year_2) {
        if (mouth_1 == mouth_2) {
            if (day_1 > day_2) {
                flag = false;
            }
        } else if (mouth_1 > mouth_2) {
            flag = false;
        }
    } else if (year_1 > year_2) {
        flag = false;
    }
    return flag;
}

void depozit::on_add_add_clicked() {
    QString temp = ui->add->text() + " " + ui->add_time->text();
    std::string tmp = temp.toStdString();
    tmp = tmp.substr(tmp.length() - 10, 10);
    if (check(tmp)) {
        ui->add_list->setText(temp);
    } else {
        QMessageBox::critical(this, "ERROR", "Time valid error");
        ui->add_time->setText("");
    }
}

void depozit::on_add_sub_clicked() {
    QString temp = ui->sub->text() + " " + ui->sub_time->text();
    std::string tmp = temp.toStdString();
    tmp = tmp.substr(tmp.length() - 10, 10);
    if (check(tmp)) {
        ui->sub_list->setText(temp);
    } else {
        QMessageBox::critical(this, "ERROR", "Time valid error");
        ui->sub_time->setText("");
    }
}

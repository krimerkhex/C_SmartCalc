#include "calculator.h"
#include "ui_calculator.h"

calculator::calculator(QWidget *parent) : QWidget(parent), ui(new Ui::calculator) {
    ui->setupUi(this);
    ui->formul_field->setValidator(val_form);
    ui->x_value->setValidator(val_double);
    ui->x_graf_1->setValidator(val_double);
    ui->x_graf_2->setValidator(val_double);
    ui->y_graf_1->setValidator(val_double);
    ui->y_graf_1->setValidator(val_double);
}

calculator::~calculator() {
    delete val_form;
    delete val_double;
    delete ui;
}

void calculator::on_log_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "log(");

}


void calculator::on_X_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "x");
}

void calculator::on_onedel_but_clicked() {
    std::string rdctstr = ui->formul_field->text().toUtf8().constData();
    std::string result = rdctstr.substr(0, rdctstr.length() - 1);
    ui->formul_field->setText(QString::fromStdString(result));
}


void calculator::on_alldel_but_clicked() {
    ui->formul_field->setText("");
}


void calculator::on_ln_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "ln(");
}


void calculator::on_pow_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "^");
}


void calculator::on_opbrack_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "(");
}


void calculator::on_clbrack_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + ")");
}


void calculator::on_sin_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "sin(");
}


void calculator::on_cos_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "cos(");
}


void calculator::on_tan_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "tan(");
}


void calculator::on_sqrt_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "sqrt(");
}


void calculator::on_asin_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "asin(");
}


void calculator::on_acos_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "acos(");
}


void calculator::on_atan_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "atan(");
}


void calculator::on_mod_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "mod");
}


void calculator::on_dev_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "/");
}


void calculator::on_num7_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "7");
}


void calculator::on_num8_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "8");
}


void calculator::on_num9_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "9");
}


void calculator::on_mult_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "*");
}


void calculator::on_num4_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "4");
}


void calculator::on_num5_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "5");
}


void calculator::on_num6_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "6");
}


void calculator::on_sub_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "-");
}


void calculator::on_num1_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "1");
}


void calculator::on_num2_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "2");
}


void calculator::on_num3_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "3");
}


void calculator::on_add_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "+");
}


void calculator::on_num0_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + "0");
}


void calculator::on_dot_but_clicked() {
    ui->formul_field->setText(ui->formul_field->text() + ".");
}

void calculator::inicilization(to_brains *strct, bool flag) {
    strct->x_value = ui->x_value->text().toDouble();
    strct->flag = flag;
    std::string x = ui->x_value->text().toStdString();
    strct->error = 0;
}

void calculator::graf(int count) {
    graf_data data;
    data.definition_x1 = (ui->x_graf_1->text().toDouble() < ui->x_graf_2->text().toDouble()) ? ui->x_graf_1->text().toDouble() : ui->x_graf_2->text().toDouble();
    data.definition_x2 = (ui->x_graf_2->text().toDouble() < ui->x_graf_1->text().toDouble()) ? ui->x_graf_1->text().toDouble() : ui->x_graf_2->text().toDouble();
    data.definition_y1 = (ui->y_graf_1->text().toDouble() < ui->y_graf_2->text().toDouble()) ? ui->y_graf_1->text().toDouble() : ui->y_graf_2->text().toDouble();
    data.definition_y2 = (ui->y_graf_2->text().toDouble() < ui->y_graf_1->text().toDouble()) ? ui->y_graf_1->text().toDouble() : ui->y_graf_2->text().toDouble();
    if ((data.definition_x1 != data.definition_x2) && (data.definition_y1 != data.definition_y2) &&
        (data.definition_x1 >= _MIN_) && (data.definition_x1 <= _MAX_) && (data.definition_x2 >= _MIN_) && (data.definition_x2 <= _MAX_) &&
        (data.definition_y1 >= _MIN_) && (data.definition_y1 <= _MAX_) && (data.definition_y2 >= _MIN_) && (data.definition_y2 <= _MAX_)) {
        int limit = (fabs(data.definition_x1)+fabs(data.definition_x2)) * 100;
        ui->widget->addGraph();
        QVector<double> x(limit), y(limit);
        double x_value = data.definition_x1;
        for (int i= 0; i < limit; i++) {
          x[i] = x_value;
          to_brains data_1;
          std::string temp_1 = ui->formul_field->text().toUtf8().constData();
          const char* temp = temp_1.c_str();
          data_1.error = 0; data_1.flag = 1; data_1.x_value = x_value;
          back(&data_1, temp);
          y[i] = data_1.result;
          x_value+=0.01;
        }
        ui->widget->graph(count)->addData(x, y);
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");
        ui->widget->xAxis->setRange(data.definition_x1, data.definition_x2);
        ui->widget->yAxis->setRange(data.definition_y1, data.definition_y2);
        if (count != 0) { ui->widget->graph(count - 1)->data()->clear(); }
        ui->widget->replot();
    } else {
        QMessageBox::critical(this, "ERROR", "Value eq error!");
        ui->x_graf_1->setText("0.0");
        ui->x_graf_2->setText("0.0");
        ui->y_graf_1->setText("0.0");
        ui->y_graf_2->setText("0.0");
    }
}

void calculator::on_equally_but_clicked() {
    if (ui->formul_field->text().length() > 256) {
        QMessageBox::critical(this, "Error", "Too a lot chars!");
    } else {
        std::string result = ui->formul_field->text().toUtf8().constData();
        to_brains init;
        (int)result.find('x') != -1 ? inicilization(&init, 1) : inicilization(&init, 0);
        std::string temp_1 = ui->formul_field->text().toUtf8().constData();
        const char* temp = temp_1.c_str();
        back(&init, temp);
        if (!init.error) {
            QMessageBox::information(this, "Answer", QString::number(init.result, 'g', 7));
            if (init.flag) { graf(count); count++;}
        } else {
            QMessageBox::critical(this, "Error", "Validation error!");
            ui->formul_field->setText("");
            ui->x_value->setText("0.0");
        }
    }
}

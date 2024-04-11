#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QListWidget>
#include <iostream>
#include <QMessageBox>
#include <QValidator>
#include <typeinfo>
#include "qcustomplot.h"
#include <math.h>

#define _MAX_ 100000
#define _MIN_ -100000

#ifdef __cplusplus
extern "C"{
#endif

    #include "s21_smart_calc.h"

#ifdef __cplusplus
}
#endif

struct graf_data{
    double definition_x1;
    double definition_x2;
    double definition_y1;
    double definition_y2;
};

namespace Ui { class calculator; }

class calculator : public QWidget{
    Q_OBJECT

public:
    QRegularExpressionValidator *val_form = new QRegularExpressionValidator(QRegularExpression("^([-]?\\d*[.]?\\d*|[+-/*^]|mod|[(]|[)]|sin[(]|cos[(]|tan[(]|sqrt[(]|asin[(]|acos[(]|atan[(]|log[(]|ln[(]|[x]){0,}$"), 0);
    QRegularExpressionValidator *val_double = new QRegularExpressionValidator(QRegularExpression("[-]?\\d*[.]?\\d*"), 0);
    explicit calculator(QWidget *parent = nullptr);
    int count = 0;
    ~calculator();

signals:
     void showWindow();
     void deletevald();

private slots:
     void on_log_but_clicked();
     void on_X_but_clicked();
     void on_onedel_but_clicked();
     void on_alldel_but_clicked();
     void on_ln_but_clicked();
     void on_pow_but_clicked();
     void on_opbrack_but_clicked();
     void on_clbrack_but_clicked();
     void on_sin_but_clicked();
     void on_cos_but_clicked();
     void on_tan_but_clicked();
     void on_sqrt_but_clicked();
     void on_asin_but_clicked();
     void on_acos_but_clicked();
     void on_atan_but_clicked();
     void on_mod_but_clicked();
     void on_dev_but_clicked();
     void on_num7_but_clicked();
     void on_num8_but_clicked();
     void on_num9_but_clicked();
     void on_mult_but_clicked();
     void on_num4_but_clicked();
     void on_num5_but_clicked();
     void on_num6_but_clicked();
     void on_sub_but_clicked();
     void on_num1_but_clicked();
     void on_num2_but_clicked();
     void on_num3_but_clicked();
     void on_add_but_clicked();
     void on_num0_but_clicked();
     void on_dot_but_clicked();
     void on_equally_but_clicked();
     void inicilization(to_brains *strct, bool flag);
     void graf(int count);

private:
    Ui::calculator *ui;
};

#endif // CALCULATOR_H

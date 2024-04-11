#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>
#include <iostream>
#include <stdlib.h>
#include <QMessageBox>
#include <QValidator>

#ifdef __cplusplus
extern "C"{
#endif

    #include "s21_credit.h"

#ifdef __cplusplus
}
#endif

namespace Ui {
class credit;
}

class credit : public QWidget
{
    Q_OBJECT

public:
    QRegularExpressionValidator *val_double_1 = new QRegularExpressionValidator(QRegularExpression("^\\d*[.]?\\d*$"), 0);
    QRegularExpressionValidator *val_double_3 = new QRegularExpressionValidator(QRegularExpression("^\\d*$"), 0);
    QRegularExpressionValidator *val_double_4 = new QRegularExpressionValidator(QRegularExpression("^(([0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3}):(((0[13578]|1[02]):(0[1-9]|[12][0-9]|3[01]))|((0[469]|11):(0[1-9]|[12][0-9]|30))|(02:(0[1-9]|[1][0-9]|2[0-8]))))|((([0-9]{2})(0[48]|[2468][048]|[13579][26])|((0[48]|[2468][048]|[3579][26])00)):02:29)$"), 0);
    explicit credit(QWidget *parent = nullptr);
    ~credit();

signals:
     void showWindow(); // Сигнал на открытие данного окна
     void deletevald();

private slots:

    void inicilization(to_brains_credit *strct);
    void on_pushButton_clicked();

private:
    Ui::credit *ui;
};

#endif // CREDIT_H

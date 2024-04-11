#ifndef DEPOZIT_H
#define DEPOZIT_H

#include <QWidget>
#include <QListWidget>
#include <iostream>
#include <QMessageBox>
#include <QValidator>
#include <string>

#ifdef __cplusplus
extern "C"{
#endif

    #include "s21_depozit.h"

#ifdef __cplusplus
}
#endif

namespace Ui { class depozit; }

class depozit : public QWidget
{
    Q_OBJECT

public:
    QRegularExpressionValidator *val_double_1 = new QRegularExpressionValidator(QRegularExpression("^\\d*[.]?\\d*$"), 0);
    QRegularExpressionValidator *val_double_3 = new QRegularExpressionValidator(QRegularExpression("^\\d*$"), 0);
    QRegularExpressionValidator *val_double_4 = new QRegularExpressionValidator(QRegularExpression("^(([0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3}):(((0[13578]|1[02]):(0[1-9]|[12][0-9]|3[01]))|((0[469]|11):(0[1-9]|[12][0-9]|30))|(02:(0[1-9]|[1][0-9]|2[0-8]))))|((([0-9]{2})(0[48]|[2468][048]|[13579][26])|((0[48]|[2468][048]|[3579][26])00)):02:29)$"), 0);
    explicit depozit(QWidget *parent = nullptr);
    ~depozit();

signals:
     void showWindow();
     void deletevald();


private slots:

     void inicilization(to_brains_depozit *strct);
     void on_run_clicked();
     void on_add_add_clicked();
     void on_add_sub_clicked();
     bool check(std::string time);

private:
    Ui::depozit *ui;
};

#endif // DEPOZIT_H


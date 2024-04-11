 #ifndef SRC_UI_S21_CREDIT_H_
 #define SRC_UI_S21_CREDIT_H_

#include <math.h>
#include <stdlib.h>
#include <string.h>

struct to_brains_credit {
    double sum_credit;
    double procent;
    int time;
    int year;
    int mouth;
    int day;
    int repay_proc;
    double all_gived;
    double gived_more;
    double* sum_per_mouth;
    int status_error;
};

// Функции в релиз
/**
 * @brief Функция для вычисления кредита
 * с аннуитетным типом платежа
 * @param data структура из GUI Credit.ui
 */
void annuity_reckon(struct to_brains_credit* data);

/**
 * @brief Функция для вычисления кредита
 * с дифференцированным типом платежа
 * @param data структура из GUI Credit.ui
 */
void differentiated_reckon(struct to_brains_credit* data); 

/**
 * @brief Функция развилка
 * на 2 типа платежей
 * @param data структура из GUI Credit.ui
 */
void distributio(struct to_brains_credit* data);

/**
 * @brief Т.к кол-во дней в каждом месяце различается
 * данная функция возращает количество дней в данном
 * месяце
 * @param data структура из GUI Credit.ui
 * @return int количество дней в текущем месяце
 */
int count_day(struct to_brains_credit* data);
#endif //SRC_UI_S21_CREDIT_H_

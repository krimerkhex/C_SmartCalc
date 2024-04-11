#ifndef SRC_UI_S21_DEPOZIT_H_
#define SRC_UI_S21_DEPOZIT_H_

#include <stdio.h>
#include <math.h>

struct to_brains_depozit {
   double sum_contr;
   int time;
   double procent;
   double tax;
   /**
    * @brief
    * 0 - Ежеквартально
    * 1 - Ежегодно
    */
   int payment_per;
   /**
    * @brief
    * 0 - Нет
    * 1 - Ежеквартально
    * 2 - Ежегодно
    */
   int payment_flag;
   int year;
   int mouth;
   int day;
   double sum_end;
   double sum_procent;
   double sum_tax;
   int status_error;
   double sum_add;
   int add_year;
   int add_mouth;
   int add_day;
   double sum_sub;
   int sub_year;
   int sub_mouth;
   int sub_day;
};

/**
 * @brief Функция развилка
 * на 2 типа начилений с капитализацией процента и без нее
 * @param data структура из GUI Depozit.ui
 */
void distribut(struct to_brains_depozit* data);

/**
 * @brief Функция вычисляющая депозит с 
 * tax == 0 && payment_per == 0, для вычисления используется
 * формула простого процента и подсчет подневный
 * @param data структура из GUI Depozit.ui
 */
void simple_procent(struct to_brains_depozit* data);

/**
 * @brief Функция вычисляющая депозит с 
 * tax != 0 && payment_per != 0, для вычисления используется
 * формула сложного процента и подсчет подневный
 * @param data 
 */
void hard_procent(struct to_brains_depozit* data);

/**
 * @brief Т.к кол-во дней в каждом месяце различается
 * данная функция возращает количество днец в данном
 * месяце
 * @param data структура из GUI Credit.ui
 * @return int количество дней в текущем месяце
 */
int coun_days(struct to_brains_depozit* data);

/**
 * @brief Добавление суммы
 * 
 * @param data структура данных
 * @param i месяц
 * @param j день
 * @param z год
 */
void addTime(struct to_brains_depozit* data, int i, int j, int z);

/**
 * @brief Изъятие суммы
 * 
 * @param data структура данных
 * @param i месяц
 * @param j день
 * @param z год
 */
void subTime(struct to_brains_depozit* data, int i, int j, int z);
#endif //SRC_UI_S21_DEPOZIT_H_

#ifndef SRC_UI_S21_SMART_CALC_H_
#define SRC_UI_S21_SMART_CALC_H_

#include "s21_struct.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

#define NUM 1
#define SUM 2
#define SUB 3
#define MLT 4
#define DIV 5
#define MOD 6
#define POW 7
#define SQRT 8
#define LOG 9
#define LN 10
#define SIN 11
#define COS 12
#define TAN 13
#define ATAN 14
#define ACOS 15
#define ASIN 16
#define O_B 17
#define C_B 18
#define X 19
#define UNARNIY_MINUS 20

/**
 * @brief Структура заполняеммая в GUI
 * @param formul формула
 * @param result результат выражения
 * @param error проверка на любую ошибку
 * @param flag 0 в выражении нет _x_ | 1 в выражении _x_
 * @param x_value значение _x_
 */
struct to_brains {
   char* formul;
   double result;
   int error;
   int flag;
   double x_value;
};

/**
 * @brief Функция получения данных из GUI, основная функция
 * (P.S если работать с data->formuul, получишь signal=11, по этому  const char* temp)
 * @param data структура с данными
 * @param temp переменая, в которой хранится строка
 */
void back(struct to_brains* data, const char* temp);

/**
 * @brief Получает указатель на очередь, в которой хранится выражение
 * 
 * @param data структура с данными
 * @param str переменая, в которой хранится строка
 * @return struct queue* указатель на очередь 
 */
struct queue* get_ends_queue(struct to_brains* data, const char* str);

/**
 * @brief Функция парса строки
 * 
 * @param data структура с данными
 * @param i переменная поиндексного обращения к строке(имеет свойство делать сдвиг)
 * @param stack структура стека
 * @param token структура очереди
 * @param unar флаг унарного минуса
 * @param str тут хранится формула
 * @return int приравнивается i для сдвига
 */
int parse(struct to_brains* data, int i, struct stack* stack, struct queue* token, int* unar, const char* str);

/**
 * @brief Проверка числа на точку
 * 
 * @param str формула
 * @return int возвращает сдвиг числа
 */
int number_is_double(const char* str);

/**
 * @brief Функция переноса значений из стека в очередь
 * 
 * @param stack стек
 * @param data структура данных
 * @param token очередь
 */
void value_skob(struct stack* stack, struct to_brains* data, struct queue* token);

/**
 * @brief Функция для растановки правильной очередности операторов
 * 
 * @param oper хранит значение операции (#define)
 * @return int 0 скобки | 1 операции
 */
int bin_for_preo(int oper);

/**
 * @brief Функция расстановки приоритетов операций по мат. правилам
 * 
 * @param oper хранит значение операции (#define)
 * @return int приоритет
 */
int preority(int oper);

/**
 * @brief Возвращает значение операции (#define)
 * 
 * @param oper символ операции
 * @return int значение операции (#define)
 */
int oper_in_string(char oper);

/**
 * @brief Возвращает значение операции (#define)
 * 
 * @param str строка операции
 * @return int значение операции (#define)
 */
int func_in_string(const char* str);

/**
 * @brief Shift для i
 * 
 * @param operation значение операции (#define)
 * @return int на сколько нужно сделать свиг
 */
int displacement(int operation);

/**
 * @brief Функция переноса данных из стека в очередь с учетом
 * приоритета текущей операции
 * 
 * @param stack стек
 * @param o значение операции (#define)
 * @param token очередь
 */
void preority_in_st(struct stack* stack, int o, struct queue* token);
void calculat(struct queue* queue, struct to_brains* data);
void end(struct stack *stack, int operation, double value, struct to_brains* data);
double unar_m(double v);
double sum(double v_1, double v_2);
double sub(double v_1, double v_2);
double mult(double v_1, double v_2);
double divis(double v_1, double v_2);
double(*get_bin(int operat))(double,  double);
double(*get_func(int operat))(double);

#endif //SRC_UI_S21_SMART_CALC_H_

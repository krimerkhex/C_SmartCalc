#ifndef SRC_UI_S21_STRUCT_H_
#define SRC_UI_S21_STRUCT_H_

#include <stdlib.h>

/**
 * @brief Основная еденица прасинга строки (односвязный список)
 * @param operation  хранит значение операции (#define)
 * @param value число
 * @param next указатель на следующий узел списка
 */
struct knot {
    int operation;
    double value;
    struct knot *next;
};

/**
 * @brief Инициализация узла
 * 
 * @param operation  хранит значение операции (#define)
 * @param value число
 * @param next указатель на следующий узел списка
 */
struct knot *init_knot(int operation, double value);

/**
 * @brief Структура очереди
 * @param first указатель на предыдущий узел
 */
struct queue {
    struct knot *first;
};

/**
 * @brief Инициализация очереди
 * 
 * @return struct queue* 
 */
struct queue *init_queue();

/**
 * @brief Добавление значения в очередь
 * 
 * @param head указатель на очередбь
 * @param operation  хранит значение операции (#define)
 * @param value число
 */
void push_queue(struct queue *head, int operation, double value);

/**
 * @brief Получение значений из очереди с удалением узла
 * 
 * @param head указатель на очередь
 * @param operation  хранит значение операции (#define)
 * @param value число
 * @return int 0 - следующий элемент существует | 1 - элемента нет
 */
int pop_queue(struct queue *head, int *operation, double *value);

/**
 * @brief Клонирование очереди
 * 
 * @param from указатель на очередь, которую нужно коипровать
 * @return struct queue* указатель на 1 узел новой очереди
 */
struct queue *clone_queue(struct queue *from);

/**
 * @brief Очистка очереди
 * 
 * @param head указатель на очередь
 */
void destroy_queue(struct queue* head);

/**
 * @brief Структура стека
 * @param back указатель на узел
 */
struct stack {
    struct knot *back;
};

/**
 * @brief Инициализация стека
 * 
 * @return struct stack* указатель на стек
 */
struct stack *init_stack();

/**
 * @brief Добавления узла в стек
 * 
 * @param head указатель на стек
 * @param operation  хранит значение операции (#define)
 * @param value число
 */
void push_stack(struct stack *head, int operation, double value);

/**
 * @brief Получение данных из стека с удалением узла
 * 
 * @param head указатель на стек
 * @param operation  хранит значение операции (#define)
 * @param value число
 * @return int 0 - следующий элемент существует | 1 - элемента нет
 */
int pop_stack(struct stack *head, int *operation, double *value);

/**
 * @brief Очистка стека
 * 
 * @param head указатель на стек
 */
void destroy_stack(struct stack *head);

/**
 * @brief Клонирование стека
 * 
 * @param from указатель на стек
 * @return struct stack* указатель на первый элемент нового стека
 */
struct stack *clone_stack(struct stack *from);

#endif // SRC_UI_S21_STRUCT_H_
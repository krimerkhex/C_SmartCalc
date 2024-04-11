#include "s21_smart_calc.h"

void back(struct to_brains* data, const char* temp) {
    const char* str = temp;
    data->result = 0.0;
    struct queue* queue = get_ends_queue(data, str);
    if (data->error == 0) {
        calculat(clone_queue(queue), data);
    }
    destroy_queue(queue);
}

struct queue* get_ends_queue(struct to_brains* data, const char* str) {
    struct queue* token = init_queue();
    struct stack* stack = init_stack();
    int unar = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        i = parse(data, i, stack, token, &unar, str);
    }
    int op = 0; double val = 0.0;
    while (!pop_stack(stack, &op, &val)) {
        push_queue(token, op, val);
    }
    destroy_stack(stack);
    return token;
}

int parse(struct to_brains* data, int i, struct stack* stack, struct queue* token,
    int* unar, const char* str) {
    if (str[i] >= '0' && str[i] <= '9') {
        double temp_value = 0.0;
        sscanf(str + i, "%lf", &temp_value);
        i = i + number_is_double(str + i) - 1;
        *unar = 0;
        push_queue(token, NUM, temp_value);
    } else if (str[i] == 'x') {
        double x_value = data->x_value;
        push_queue(token, X, x_value);
    } else if (str[i] == '-' && (*unar)) {
        push_stack(stack, UNARNIY_MINUS, 0);
    } else if (oper_in_string(str[i]) != -1) {
        int operat = oper_in_string(str[i]);
        if (operat == C_B) {
            value_skob(stack, data, token);
            *unar = 0;
        } else if (operat == POW) {
            if (stack->back != NULL) {
                if (stack->back->operation != POW) {
                    preority_in_st(stack, operat, token);
                }
            }
            preority_in_st(stack, operat, token);
            push_stack(stack, operat, 0);
            *unar = 1;
        } else if (bin_for_preo(operat)) {
            preority_in_st(stack, operat, token);
            push_stack(stack, operat, 0);
            *unar = 1;
        } else {
            push_stack(stack, operat , 0);
            *unar = 1;
        }
    } else if (func_in_string(str + i) != -1) {
        int operat = func_in_string(str + i);
        preority_in_st(stack, operat, token);
        if (operat == MOD) {
            push_stack(stack, MOD, 0);
        } else {
            push_stack(stack, operat, 0);
            push_stack(stack, O_B, 0);
        }
        *unar = 1;
        i += displacement(operat);
    } else {
        data->error = 1;
    }
    return i;
}

int number_is_double(const char* str) {
    int dot = 0;
    int i = 0;
    while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.' && !dot)) {
        if (str[i] == '.') {
            dot = 1;
        }
        i++;
    }
    return i;
}

void value_skob(struct stack* stack, struct to_brains* data, struct queue* token) {
    int t_o = 0; double t_v = 0.0;
    while (!pop_stack(stack, &t_o, &t_v) && t_o != O_B) {
        push_queue(token, t_o, t_v);
    }
    if (t_o != O_B) {
        data->error = 1;
    }
}

void preority_in_st(struct stack* stack, int o, struct queue* token) {
    while (stack->back && preority(stack->back->operation) >= preority(o)) {
        int t_o = 0; double t_v = 0.0;
        pop_stack(stack, &t_o, &t_v);
        push_queue(token, t_o, t_v);
    }
}

int bin_for_preo(int oper) {
    int value = 0;
    if (oper == MLT || oper == DIV || oper == SUB || oper == SUM || oper == POW || oper == MOD)
        value = 1;
    return value;
}

int preority(int oper) {
    int preo = -1;
    preo = (oper == SUM || oper == SUB || oper == UNARNIY_MINUS) ? 1: preo;
    preo = (oper == MLT || oper == DIV || oper == MOD) ? 2: preo;
    preo = (oper == POW) ? 3: preo;
    preo = (oper == SIN || oper == COS || oper == TAN ||
            oper == ASIN || oper == ACOS || oper == ATAN ||
            oper == SQRT || oper == LOG || oper == LN) ? 4: preo;
    return preo;
}

int oper_in_string(char oper) {
    int value = -1;
    value = oper == 'x' ? X : value;
    value = oper == '+' ? SUM : value;
    value = oper == '-' ? SUB : value;
    value = oper == '/' ? DIV : value;
    value = oper == '*' ? MLT : value;
    value = oper == '^' ? POW : value;
    value = oper == '(' ? O_B : value;
    value = oper == ')' ? C_B : value;
    return value;
}

int func_in_string(const char* str) {
    int value = -1;
    value = !strncmp(str, "sin(", 4) ? SIN : value;
    value = !strncmp(str, "cos(", 4) ? COS : value;
    value = !strncmp(str, "tan(", 4) ? TAN : value;
    value = !strncmp(str, "asin(", 5) ? ASIN : value;
    value = !strncmp(str, "acos(", 5) ? ACOS : value;
    value = !strncmp(str, "atan(", 5) ? ATAN : value;
    value = !strncmp(str, "sqrt(", 5) ? SQRT : value;
    value = !strncmp(str, "log(", 4) ? LOG : value;
    value = !strncmp(str, "ln(", 3) ? LN : value;
    value = !strncmp(str, "mod", 3) ? MOD : value;
    return value;
}

int displacement(int operation) {
    int value = 0;
    value = (operation == LN ||
        operation == MOD) ? 2 : value;
    value = (operation == LOG ||operation == TAN ||
               operation == COS ||operation == SIN) ? 3 : value;
    value = (operation == SQRT || operation == ATAN ||
               operation == ACOS || operation == ASIN) ? 4 : value;
    return value;
}

void calculat(struct queue* queue, struct to_brains* data) {
    int t_o = 0, i = 0;
    double t_v = 0.0;
    struct stack* stack = init_stack();
    while (!pop_queue(queue, &t_o, &t_v)) {
        end(stack, t_o, t_v, data);
        if (data->error == 1) {
            break;
        }
        i++;
    }
    pop_stack(stack, &t_o, &t_v);
    destroy_queue(queue);
    destroy_stack(stack);
    data->result = round(t_v * 1000000) / 1000000;
}

void end(struct stack *stack, int operation, double value, struct to_brains* data) {
    if (operation == NUM) {
        push_stack(stack, NUM, value);
    } else if (operation == X) {
        if (data->flag == 1) {
            push_stack(stack, X, data->x_value);
        } else {
            data->error = 1;
        }
    } else if (get_bin(operation) != NULL) {
        double v_1 = 0, v_2 = 0;
        double (*f)(double a, double b) = get_bin(operation);
        pop_stack(stack, &operation, &v_1);
        pop_stack(stack, &operation, &v_2);
        if (*f == divis && v_1 == 0) {
            data->error = 1;
        } else {
            v_1 = f(v_2, v_1);
            push_stack(stack, operation, v_1);
        }
    } else if (get_func(operation) != NULL) {
        int flag = 0;
        double (*f)(double a) = get_func(operation);
        if (operation == SQRT || operation == LOG || operation == LN) { flag = 1; }
        pop_stack(stack, &operation, &value);
        if (flag == 1 && value < 0) { data->error = 1; }
        value = f(value);
        push_stack(stack, operation, value);
    } else {
        data->error = 1;
    }
}

double(*get_func(int operat))(double) {
    double (*oper)(double a) = NULL;
    oper = (operat == UNARNIY_MINUS) ? unar_m : oper;
    oper = (operat == COS) ? cos: oper;
    oper = (operat == SIN) ? sin: oper;
    oper = (operat == TAN) ? tan: oper;
    oper = (operat == ACOS) ? acos: oper;
    oper = (operat == ASIN) ? asin: oper;
    oper = (operat == ATAN) ? atan: oper;
    oper = (operat == SQRT) ? sqrt: oper;
    oper = (operat == LOG) ? log10: oper;
    oper = (operat == LN) ? log: oper;
    return oper;
}

double(*get_bin(int operat))(double,  double) {
    double (*oper)(double a, double b) = NULL;
    oper = (operat == SUM) ? sum: oper;
    oper = (operat == SUB) ? sub: oper;
    oper = (operat == MLT) ? mult: oper;
    oper = (operat == DIV) ? divis: oper;
    oper = (operat == POW) ? pow: oper;
    oper = (operat == MOD) ? fmod: oper;
    return oper;
}

double unar_m(double v) {
    return 0 - v;
}

double sum(double v_1, double v_2) {
    return v_1 + v_2;
}

double sub(double v_1, double v_2) {
    return v_1 - v_2;
}

double mult(double v_1, double v_2) {
    return v_1 * v_2;
}

double divis(double v_1, double v_2) {
    return v_1 / v_2;
}

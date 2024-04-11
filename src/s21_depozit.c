#include "s21_depozit.h"

void distribut(struct to_brains_depozit* data) {
    if (data->payment_flag == 0) {
        simple_procent(data);
    } else if (data->payment_flag != 0) {
        hard_procent(data);
    } else {
        data->status_error = 1;
    }
}

void addTime(struct to_brains_depozit* data, int i, int j, int z) {
    if (j + 1 == data->add_day && i + 1 == data->add_mouth &&
    z == data->add_year) {
        data->sum_contr += data->sum_add;
    }
}

void subTime(struct to_brains_depozit* data, int i, int j, int z) {
    if (j + 1 == data->sub_day && i + 1 == data->sub_mouth  &&
    z == data->sub_year) {
        if (data->sum_contr + data->sum_procent < data->sum_sub) {
            data->status_error = 1;
        } else {
            data->sum_contr -= data->sum_sub;
        }
    }
}

void simple_procent(struct to_brains_depozit* data) {
    for (int i = 0; i < data->time; i++) {
        int year = data->year;
        int value = coun_days(data) - data->day; data->day = 0;
        for (int j = data->day; j < value; j++) {
            addTime(data, j, i, year); subTime(data, j, i, year);
        }
        if (data->payment_per == 0) {
            for (int j = data->day; j < value; j++) {
                data->sum_procent += data->sum_contr *
                data->procent / 100. / (data->year % 4 == 0 ? 366. : 365.);
                data->sum_tax += data->sum_contr *
                data->tax / 100. / (data->year % 4 == 0 ? 366. : 365.);
            }
        }
        if (data->payment_per == 1) {
            data->sum_procent += data->sum_contr * (double)coun_days(data) *
            data->procent / 100. / (data->year % 4 == 0 ? 366. : 365.);
            data->sum_tax += data->sum_contr * (double)coun_days(data) *
            data->tax / 100. / (data->year % 4 == 0 ? 366. : 365.);
        }
        (data->mouth == 12) ? data->mouth = 1, data->year++ : data->mouth++;
    }
    data->sum_end = data->sum_contr + data->sum_procent - data->sum_tax;
}

void hard_procent(struct to_brains_depozit* data) {
    data->tax = (data->tax == 0) ? 1 : data->tax;
    double start_sum = data->sum_contr;
    double temp_procent = 0.0;
    for (int i = 0; i < data->time; i++) {
        int year = data->year;
        int value = coun_days(data) - data->day; data->day = 0;
        for (int j = data->day; j < value; j++) {
            addTime(data, j, i, year); subTime(data, j, i, year);
        }
        if (data->payment_per == 0 && data->payment_flag == 1) {
            for (int j = 0; j < value; j++) {
            data->sum_contr += round(temp_procent * 100) / 100.; temp_procent = 0.0;
            temp_procent += (data->sum_contr * data->procent / 100.
            / (data->year % 4 == 0 ? 366. : 365.));
            }
        } else {
            data->sum_contr += round(temp_procent * 100) / 100.; temp_procent = 0.0;
            temp_procent += (data->sum_contr * data->procent / 100.
            * (double)coun_days(data) / (data->year % 4 == 0 ? 366. : 365.));
        }
        (data->mouth == 12) ? data->mouth = 1, data->year++ : data->mouth++;
    }
    data->sum_procent = data->sum_contr - start_sum;
    data->sum_tax = data->sum_procent * data->tax /100.;
    data->sum_end = data->sum_contr - data->sum_tax;
}

int coun_days(struct to_brains_depozit* data) {
    int days = 0;
    if (data->mouth == 4 || data->mouth == 6
        || data->mouth == 11) {
        days = 30;
    } else if (data->mouth == 2) {
        days = data->year % 4 == 0 ? 29 : 28;
    } else {
        days = 31;
    }
    return days;
}

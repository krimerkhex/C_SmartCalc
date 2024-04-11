#include "s21_credit.h"

void distributio(struct to_brains_credit* data) {
    if (!data->status_error) {
        switch (data->repay_proc) {
        case 0:
            annuity_reckon(data);
            break;
        case 1:
            differentiated_reckon(data);
            break;
        default:
            break;
        }
    }
}

int count_day(struct to_brains_credit* data) {
    int days = 0;
    if (data->mouth == 4 || data->mouth == 6
        || data->mouth == 11) {
        days = 30;
    } else if (data->mouth == 2) {
        days = 28;
    } else {
        days = 31;
    }
    return days;
}

void annuity_reckon(struct to_brains_credit* data) {
    double loan_rate = data->procent/12./100.;
    double an_coef = loan_rate*(powl(1+loan_rate, (double)data->time))
            /((powl(1+loan_rate, (double)data->time) - 1));
    double* temp = calloc(sizeof(double), data->time);
    if (temp != NULL) {
        temp[0] = (an_coef * data->sum_credit / data->time);
        data->sum_per_mouth = temp;
        data->gived_more = (temp[0] * data->time);
        data->all_gived = fabs(data->sum_credit + data->gived_more);
//        free(temp);
    } else {
        data->status_error = 1;
    }
}

void differentiated_reckon(struct to_brains_credit* data) {
    double* all_pays = calloc(sizeof(double), data->time);
    if (all_pays != NULL) {
        data->all_gived = 0;
        double pays = data->sum_credit / data->time;
        for (int i = 0; i < data->time; i++) {
            all_pays[i] = pays + (data->sum_credit - (pays * i)) * 0.1/12;
            data->all_gived += all_pays[i];
        }
        data->sum_per_mouth = all_pays;
        data->gived_more = fabs(fabs(data->all_gived) - fabs(data->sum_credit));
        data->all_gived = fabs(data->all_gived);
//        free(all_pays);
    } else {
        data->status_error = 1;
    }
}


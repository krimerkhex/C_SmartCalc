#include <check.h>
#include "s21_smart_calc.h"
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>

START_TEST(test_1) {
    struct to_brains data;
    char* temp = "0.0";
    data.flag = 0;
    data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 0.0);
    }
}
END_TEST

START_TEST(test_2) {
    struct to_brains data;
    char* temp = "-1";
    data.flag = 0;
    data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, -1);
    }
}
END_TEST

START_TEST(test_3) {
    struct to_brains data;
    char* temp = "-0";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 0);
    }
}
END_TEST

START_TEST(test_4) {
    struct to_brains data;
    char* temp = "--0";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
}
END_TEST

START_TEST(test_5) {
    struct to_brains data;
    char* temp = "x";
    data.x_value = 0.1;
    data.flag = 1;
    data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 0.1);
    }
}
END_TEST

START_TEST(test_6) {
    struct to_brains data;
    char* temp = "x";
    data.x_value = -1;
    data.flag = 1;
    data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, -1);
    }
}
END_TEST

START_TEST(test_7) {
    struct to_brains data;
    char* temp = "0.1+0.1";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 0.2);
    }
}
END_TEST

START_TEST(test_8) {
    struct to_brains data;
    char* temp = "0+0";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 0);
    }
}
END_TEST

START_TEST(test_9) {
    struct to_brains data;
    char* temp = "1500+1500";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 3000);
    }
}
END_TEST

START_TEST(test_10) {
    struct to_brains data;
    char* temp = "0.1-0.1";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 0);
    }
}
END_TEST

START_TEST(test_11) {
    struct to_brains data;
    char* temp = "-0.2-0.2";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, -0.4);
    }
}
END_TEST

START_TEST(test_12) {
    struct to_brains data;
    char* temp = "1500-1500";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 0);
    }
}
END_TEST

START_TEST(test_13) {
    struct to_brains data;
    char* temp = "1*1";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 1);
    }
}
END_TEST

START_TEST(test_14) {
    struct to_brains data;
    char* temp = "1.1*0.1";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 0.11);
    }
}
END_TEST

START_TEST(test_15) {
    struct to_brains data;
    char* temp = "9+9/9+9*9-9";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 82);
    }
}
END_TEST

START_TEST(test_16) {
    struct to_brains data;
    char* temp = "1*999";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 999);
     }
}
END_TEST

START_TEST(test_17) {
    struct to_brains data;
    char* temp = "-1*999";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, -999);
     }
}
END_TEST

START_TEST(test_18) {
    struct to_brains data;
    char* temp = "1/0";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 1);
}
END_TEST

START_TEST(test_19) {
    struct to_brains data;
    char* temp = "1/1";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 1);
     }
}
END_TEST

START_TEST(test_20) {
    struct to_brains data;
    char* temp = "0.1/1";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 0.1);
     }
}
END_TEST

START_TEST(test_21) {
    struct to_brains data;
    char* temp = "15/5";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 3);
     }
}
END_TEST

START_TEST(test_22) {
    struct to_brains data;
    char* temp = "15/9";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 1.666667);
     }
}
END_TEST

START_TEST(test_23) {
    struct to_brains data;
    char* temp = "0.1/0.1";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 1);
     }
}
END_TEST

START_TEST(test_24) {
    struct to_brains data;
    char* temp = "1mod1";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 0);
     }
}
END_TEST

START_TEST(test_25) {
    struct to_brains data;
    char* temp = "2mod18";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 2);
     }
}
END_TEST

START_TEST(test_26) {
    struct to_brains data;
    char* temp = "0.1mod1";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 0.1);
     }
}
END_TEST

START_TEST(test_27) {
    struct to_brains data;
    char* temp = "1^13";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 1);
     }
}
END_TEST

START_TEST(test_28) {
    struct to_brains data;
    char* temp = "-1^13";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, -1);
     }
}
END_TEST

START_TEST(test_29) {
    struct to_brains data;
    char* temp = "2^6";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 64);
     }
}
END_TEST

START_TEST(test_30) {
    struct to_brains data;
    char* temp = "0.2^6";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, 0.000064);
     }
}
END_TEST

START_TEST(test_31) {
    struct to_brains data;
    char* temp = "sin(1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(sin(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_32) {
    struct to_brains data;
    char* temp = "sin(x)";
    data.x_value = 1;
    data.flag = 1;
    data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(sin(1)* 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_33) {
    struct to_brains data;
    char* temp = "sin(-1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(sin(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_34) {
    struct to_brains data;
    char* temp = "sin(x)";
    data.x_value = -1;
    data.flag = 1;
    data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(sin(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_35) {
    struct to_brains data;
    char* temp = "cos(1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(cos(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_36) {
    struct to_brains data;
    char* temp = "cos(-1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(cos(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_37) {
    struct to_brains data;
    char* temp = "cos(x)";
    data.x_value = 1;
    data.flag = 1; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(cos(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_38) {
    struct to_brains data;
    char* temp = "cos(x)";
    data.x_value = -1;
    data.flag = 1; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, round(cos(-1) * 1000000) / 1000000);
    }
}
END_TEST

START_TEST(test_39) {
    struct to_brains data;
    char* temp = "tan(1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(tan(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_40) {
    struct to_brains data;
    char* temp = "tan(-1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(tan(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_41) {
    struct to_brains data;
    char* temp = "tan(x)";
    data.x_value = 1;
    data.flag = 1; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(tan(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_42) {
    struct to_brains data;
    char* temp = "tan(x)";
    data.x_value = -1;
    data.flag = 1; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(tan(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_43) {
    struct to_brains data;
    char* temp = "asin(1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(asin(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_44) {
    struct to_brains data;
    char* temp = "asin(-1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(asin(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_45) {
    struct to_brains data;
    char* temp = "asin(x)";
    data.x_value = 1;
    data.flag = 1; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(asin(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_46) {
    struct to_brains data;
    char* temp = "asin(x)";
    data.x_value = -1;
    data.flag = 1; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(asin(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_47) {
    struct to_brains data;
    char* temp = "acos(1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(acos(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_48) {
    struct to_brains data;
    char* temp = "acos(-1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(acos(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_49) {
    struct to_brains data;
    char* temp = "acos(x)";
    data.x_value = 1;
    data.flag = 1; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(acos(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_50) {
    struct to_brains data;
    char* temp = "acos(x)";
    data.x_value = -1;
    data.flag = 1; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(acos(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_51) {
    struct to_brains data;
    char* temp = "atan(1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(atan(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_52) {
    struct to_brains data;
    char* temp = "atan(-1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(atan(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_53) {
    struct to_brains data;
    char* temp = "atan(x)";
    data.x_value = 1;
    data.flag = 1; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(atan(1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_54) {
    struct to_brains data;
    char* temp = "atan(x)";
    data.x_value = -1;
    data.flag = 1; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(atan(-1) * 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_55) {
    struct to_brains data;
    char* temp = "log(1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, round(log10(1)* 1000000) / 1000000);
     }
}
END_TEST

START_TEST(test_56) {
    struct to_brains data;
    char* temp = "log(-1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 1);
}
END_TEST

START_TEST(test_57) {
    struct to_brains data;
    char* temp = "log(0.1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, log10(0.1));
     }
}
END_TEST

START_TEST(test_58) {
    struct to_brains data;
    char* temp = "ln(1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, log(1));
     }
}
END_TEST

START_TEST(test_59) {
    struct to_brains data;
    char* temp = "ln(-1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 1);
}
END_TEST

START_TEST(test_60) {
    struct to_brains data;
    char* temp = "ln(1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, log(1));
     }
}
END_TEST

START_TEST(test_61) {
    struct to_brains data;
    char* temp = "sqrt(1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
     ck_assert_int_eq(data.error, 0);
     if (!data.error) {
        ck_assert_double_eq(data.result, sqrt(1));
     }
}
END_TEST

START_TEST(test_62) {
    struct to_brains data;
    char* temp = "sqrt(-1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 1);
}
END_TEST

START_TEST(test_63) {
    struct to_brains data;
    char* temp = "sqrt(0)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, sqrt(0));
    }
}
END_TEST

START_TEST(test_64) {
    struct to_brains data;
    char* temp = "2^2^2";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 16);
    }
}
END_TEST

START_TEST(test_65) {
    struct to_brains data;
    char* temp = "2^0";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, 1);
    }
}
END_TEST

START_TEST(test_66) {
    struct to_brains data;
    char* temp = " ";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 1);
}
END_TEST

START_TEST(test_67) {
    struct to_brains data;
    char* temp = "cos(7)^8-7+sqrt (56)*acos(56)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 1);
}
END_TEST

START_TEST(test_68) {
    struct to_brains data;
    char* temp = "cos(7^8)-7+sqrt(56)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 0);
    if (!data.error) {
        ck_assert_double_eq(data.result, -0.407432);
    }
}
END_TEST

START_TEST(test_69) {
    struct to_brains data;
    char* temp = "x";
    data.x_value = 0.1;
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 1);
}
END_TEST

START_TEST(test_70) {
    struct to_brains data;
    char* temp = "((1)";
    data.flag = 0; data.error = 0;
    back(&data, temp);
    ck_assert_int_eq(data.error, 1);
}
END_TEST

int main(void) {
    Suite *suite = suite_create("Debuger");
    SRunner*srunner = srunner_create(suite);

    TCase *tcase_1 = tcase_create("test_1");
    suite_add_tcase(suite, tcase_1);
    tcase_add_test(tcase_1, test_1);

    TCase *tcase_2 = tcase_create("test_2");
    suite_add_tcase(suite, tcase_2);
    tcase_add_test(tcase_2, test_2);

    TCase *tcase_3 = tcase_create("test_3");
    suite_add_tcase(suite, tcase_3);
    tcase_add_test(tcase_3, test_3);

    TCase *tcase_4 = tcase_create("test_4");
    suite_add_tcase(suite, tcase_4);
    tcase_add_test(tcase_4, test_4);

    TCase *tcase_5 = tcase_create("test_5");
    suite_add_tcase(suite, tcase_5);
    tcase_add_test(tcase_5, test_5);

    TCase *tcase_6 = tcase_create("test_6");
    suite_add_tcase(suite, tcase_6);
    tcase_add_test(tcase_6, test_6);

    TCase *tcase_7 = tcase_create("test_7");
    suite_add_tcase(suite, tcase_7);
    tcase_add_test(tcase_7, test_7);

    TCase *tcase_8 = tcase_create("test_8");
    suite_add_tcase(suite, tcase_8);
    tcase_add_test(tcase_8, test_8);

    TCase *tcase_9 = tcase_create("test_9");
    suite_add_tcase(suite, tcase_9);
    tcase_add_test(tcase_9, test_9);

    TCase *tcase_10 = tcase_create("test_10");
    suite_add_tcase(suite, tcase_10);
    tcase_add_test(tcase_10, test_10);

    TCase *tcase_11 = tcase_create("test_11");
    suite_add_tcase(suite, tcase_11);
    tcase_add_test(tcase_11, test_11);

    TCase *tcase_12 = tcase_create("test_12");
    suite_add_tcase(suite, tcase_12);
    tcase_add_test(tcase_12, test_12);

    TCase *tcase_13 = tcase_create("test_13");
    suite_add_tcase(suite, tcase_13);
    tcase_add_test(tcase_13, test_13);

    TCase *tcase_14 = tcase_create("test_14");
    suite_add_tcase(suite, tcase_14);
    tcase_add_test(tcase_14, test_14);

    TCase *tcase_15 = tcase_create("test_15");
    suite_add_tcase(suite, tcase_15);
    tcase_add_test(tcase_15, test_15);

    TCase *tcase_16 = tcase_create("test_16");
    suite_add_tcase(suite, tcase_16);
    tcase_add_test(tcase_16, test_16);

    TCase *tcase_17 = tcase_create("test_17");
    suite_add_tcase(suite, tcase_17);
    tcase_add_test(tcase_17, test_17);

    TCase *tcase_18 = tcase_create("test_18");
    suite_add_tcase(suite, tcase_18);
    tcase_add_test(tcase_18, test_18);

    TCase *tcase_19 = tcase_create("test_19");
    suite_add_tcase(suite, tcase_19);
    tcase_add_test(tcase_19, test_19);

    TCase *tcase_20 = tcase_create("test_20");
    suite_add_tcase(suite, tcase_20);
    tcase_add_test(tcase_20, test_20);

    TCase *tcase_21 = tcase_create("test_21");
    suite_add_tcase(suite, tcase_21);
    tcase_add_test(tcase_21, test_21);

    TCase *tcase_22 = tcase_create("test_22");
    suite_add_tcase(suite, tcase_22);
    tcase_add_test(tcase_22, test_22);

    TCase *tcase_23 = tcase_create("test_23");
    suite_add_tcase(suite, tcase_23);
    tcase_add_test(tcase_23, test_23);

    TCase *tcase_24 = tcase_create("test_24");
    suite_add_tcase(suite, tcase_24);
    tcase_add_test(tcase_24, test_24);

    TCase *tcase_25 = tcase_create("test_25");
    suite_add_tcase(suite, tcase_25);
    tcase_add_test(tcase_25, test_25);

    TCase *tcase_26 = tcase_create("test_26");
    suite_add_tcase(suite, tcase_26);
    tcase_add_test(tcase_26, test_26);

    TCase *tcase_27 = tcase_create("test_27");
    suite_add_tcase(suite, tcase_27);
    tcase_add_test(tcase_27, test_27);

    TCase *tcase_28 = tcase_create("test_28");
    suite_add_tcase(suite, tcase_28);
    tcase_add_test(tcase_28, test_28);

    TCase *tcase_29 = tcase_create("test_29");
    suite_add_tcase(suite, tcase_29);
    tcase_add_test(tcase_29, test_29);

    TCase *tcase_30 = tcase_create("test_30");
    suite_add_tcase(suite, tcase_30);
    tcase_add_test(tcase_30, test_30);

    TCase *tcase_31 = tcase_create("test_31");
    suite_add_tcase(suite, tcase_31);
    tcase_add_test(tcase_31, test_31);

    TCase *tcase_32 = tcase_create("test_32");
    suite_add_tcase(suite, tcase_32);
    tcase_add_test(tcase_32, test_32);

    TCase *tcase_33 = tcase_create("test_33");
    suite_add_tcase(suite, tcase_33);
    tcase_add_test(tcase_33, test_33);

    TCase *tcase_34 = tcase_create("test_34");
    suite_add_tcase(suite, tcase_34);
    tcase_add_test(tcase_34, test_34);

    TCase *tcase_35 = tcase_create("test_35");
    suite_add_tcase(suite, tcase_35);
    tcase_add_test(tcase_35, test_35);

    TCase *tcase_36 = tcase_create("test_36");
    suite_add_tcase(suite, tcase_36);
    tcase_add_test(tcase_36, test_36);

    TCase *tcase_37 = tcase_create("test_37");
    suite_add_tcase(suite, tcase_37);
    tcase_add_test(tcase_37, test_37);

    TCase *tcase_38 = tcase_create("test_38");
    suite_add_tcase(suite, tcase_38);
    tcase_add_test(tcase_38, test_38);

    TCase *tcase_39 = tcase_create("test_39");
    suite_add_tcase(suite, tcase_39);
    tcase_add_test(tcase_39, test_39);

    TCase *tcase_40 = tcase_create("test_40");
    suite_add_tcase(suite, tcase_40);
    tcase_add_test(tcase_40, test_40);

    TCase *tcase_41 = tcase_create("test_41");
    suite_add_tcase(suite, tcase_41);
    tcase_add_test(tcase_41, test_41);

    TCase *tcase_42 = tcase_create("test_42");
    suite_add_tcase(suite, tcase_42);
    tcase_add_test(tcase_42, test_42);

    TCase *tcase_43 = tcase_create("test_43");
    suite_add_tcase(suite, tcase_43);
    tcase_add_test(tcase_43, test_43);

    TCase *tcase_44 = tcase_create("test_44");
    suite_add_tcase(suite, tcase_44);
    tcase_add_test(tcase_44, test_44);

    TCase *tcase_45 = tcase_create("test_45");
    suite_add_tcase(suite, tcase_45);
    tcase_add_test(tcase_45, test_45);

    TCase *tcase_46 = tcase_create("test_46");
    suite_add_tcase(suite, tcase_46);
    tcase_add_test(tcase_46, test_46);

    TCase *tcase_47 = tcase_create("test_47");
    suite_add_tcase(suite, tcase_47);
    tcase_add_test(tcase_47, test_47);

    TCase *tcase_48 = tcase_create("test_48");
    suite_add_tcase(suite, tcase_48);
    tcase_add_test(tcase_48, test_48);

    TCase *tcase_49 = tcase_create("test_49");
    suite_add_tcase(suite, tcase_49);
    tcase_add_test(tcase_49, test_49);

    TCase *tcase_50 = tcase_create("test_50");
    suite_add_tcase(suite, tcase_50);
    tcase_add_test(tcase_50, test_50);

    TCase *tcase_51 = tcase_create("test_51");
    suite_add_tcase(suite, tcase_51);
    tcase_add_test(tcase_51, test_51);

    TCase *tcase_52 = tcase_create("test_52");
    suite_add_tcase(suite, tcase_52);
    tcase_add_test(tcase_52, test_52);

    TCase *tcase_53 = tcase_create("test_53");
    suite_add_tcase(suite, tcase_53);
    tcase_add_test(tcase_53, test_53);

    TCase *tcase_54 = tcase_create("test_54");
    suite_add_tcase(suite, tcase_54);
    tcase_add_test(tcase_54, test_54);

    TCase *tcase_55 = tcase_create("test_55");
    suite_add_tcase(suite, tcase_55);
    tcase_add_test(tcase_55, test_55);

    TCase *tcase_56 = tcase_create("test_56");
    suite_add_tcase(suite, tcase_56);
    tcase_add_test(tcase_56, test_56);

    TCase *tcase_57 = tcase_create("test_57");
    suite_add_tcase(suite, tcase_57);
    tcase_add_test(tcase_57, test_57);

    TCase *tcase_58 = tcase_create("test_58");
    suite_add_tcase(suite, tcase_58);
    tcase_add_test(tcase_58, test_58);

    TCase *tcase_59 = tcase_create("test_59");
    suite_add_tcase(suite, tcase_59);
    tcase_add_test(tcase_59, test_59);

    TCase *tcase_60 = tcase_create("test_60");
    suite_add_tcase(suite, tcase_60);
    tcase_add_test(tcase_60, test_60);

    TCase *tcase_61 = tcase_create("test_61");
    suite_add_tcase(suite, tcase_61);
    tcase_add_test(tcase_61, test_61);

    TCase *tcase_62 = tcase_create("test_62");
    suite_add_tcase(suite, tcase_62);
    tcase_add_test(tcase_62, test_62);

    TCase *tcase_63 = tcase_create("test_63");
    suite_add_tcase(suite, tcase_63);
    tcase_add_test(tcase_63, test_63);

    TCase *tcase_64 = tcase_create("test_64");
    suite_add_tcase(suite, tcase_64);
    tcase_add_test(tcase_64, test_64);

    TCase *tcase_65 = tcase_create("test_65");
    suite_add_tcase(suite, tcase_65);
    tcase_add_test(tcase_65, test_65);

    TCase *tcase_66 = tcase_create("test_66");
    suite_add_tcase(suite, tcase_66);
    tcase_add_test(tcase_66, test_66);

    TCase *tcase_67 = tcase_create("test_67");
    suite_add_tcase(suite, tcase_67);
    tcase_add_test(tcase_67, test_67);

    TCase *tcase_68 = tcase_create("test_68");
    suite_add_tcase(suite, tcase_68);
    tcase_add_test(tcase_68, test_68);

    TCase *tcase_69 = tcase_create("test_69");
    suite_add_tcase(suite, tcase_69);
    tcase_add_test(tcase_69, test_69);

    TCase *tcase_70 = tcase_create("test_70");
    suite_add_tcase(suite, tcase_70);
    tcase_add_test(tcase_70, test_70);

    srunner_run_all(srunner, CK_VERBOSE);
    int fails = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    return fails == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

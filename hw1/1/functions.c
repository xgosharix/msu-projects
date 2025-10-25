#include "functions.h"
#include <stdio.h>
#include <math.h>

void creator(FILE *fp) {
    if (!fp) {
        printf("Ошибка: файл не открыт для записи.\n");
        return;
    }

    int n;
    double x;

    printf("Сколько чисел вы хотите записать в файл? ");
    scanf("%d", &n);

    printf("Введите %d чисел через пробел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x);
        fprintf(fp, "%.10g ", x);
    }

    printf("Числа успешно записаны в файл.\n");
}

int checker(FILE *fp, double x, double eps) {
    if (!fp) return 0;

    double check;
    fseek(fp, 0, SEEK_SET); // ставим курсор в начало

    while (fscanf(fp, "%lf", &check) == 1) {
        if (fabs(check - x) <= eps) {
            return 1; // нашли число, сразу возвращаем
        }
    }
    return 0;
}

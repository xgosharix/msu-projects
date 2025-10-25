#include "functions.h"
#include <stdio.h>
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

int checker(FILE *fp){
    
    double count = 0;
    double prev, curr;

    if (fscanf(fp, "%lf", &prev) != 1) {
        return 0;  // файл пустой
    }

    while (fscanf(fp, "%lf", &curr) == 1) {
        if(curr > prev){
            count++;
        }
        else if(prev > curr){
            count = count - 1;
        }
        prev = curr;
    }

    return count;
}

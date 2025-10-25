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


int max_finder(FILE *fp) {
    double prev, curr, next;
    int pos = 2;
    int max_pos = 0;
    int max_dist = 0;

    if (fscanf(fp, "%lf", &prev) != 1) return 0;
    if (fscanf(fp, "%lf", &curr) != 1) return 0;
    while (fscanf(fp, "%lf", &next) == 1) {
        if (curr > prev && curr > next) {
            if (max_pos != 0) {
                int dist = pos - max_pos;
                if (dist > max_dist) {
                    max_dist = dist;
                }
                
            }
            max_pos = pos;
        }
        
        prev = curr;
        curr = next;
        pos++;
    }

    return max_dist;
}



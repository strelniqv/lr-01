#include "arrays.h"
#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001);

    double A[CAPACITY];
    double B[CAPACITY];
    double p[3];
    int n;
    int m;

    n = read_array(A, CAPACITY);
    if (n == 0){
        printf("ошибка ввода\n");
        return 1;
    }
    
    m = read_length(CAPACITY);
    if (m == 0){
        printf("ошибка ввода\n");
        return 1;
    }

    if (read_params(p) == 0){
        printf("ошибка ввода\n");
        return 1;
    }

    build_b(B, m, p[0], p[1], p[2]);

    printf("A:\n");
    print_array(A, n);

    printf("B:\n");
    print_array(B, m);

    printf("B после удаления:\n");
    int new_m = remove_small(B, m);
    if (new_m == 0){
        printf("массив пуст\n");
    } else {
        print_array(B, new_m);
    }

    printf("A после вставки:\n");
    int new_n = insert_zero_first(A, n);
    if (new_n == -1){
        printf("нет места для вставки\n");
        new_n = n;
    } else {
        print_array(A, new_n);
    }

    printf("A после изменения:\n");
    replace_negative(A, new_n);
    if (new_n == 0){
        printf("массив пуст\n");
    } else {
        print_array(A, new_n);
    }

    return 0;
}
#include "arrays.h"
#include <stdio.h>
#include <math.h>

// функции ввода
int read_array(double A[], int capacity)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1 || n > capacity){
        return 0;
    }

    for (int i = 0; i < n; ++i){
        if (scanf("%lf", &A[i]) != 1){
            return 0;
        }
    }
    
    return n;
}

int read_length(int capacity)
{
    int m;

    if (scanf("%d", &m) != 1){
        return 0;
    }

    if (m < 1 || m > capacity){
        return 0;
    }
    
    return m;
}

int read_params(double p[])
{
    if (scanf("%lf %lf %lf", &p[0], &p[1], &p[2]) != 3){
        return 0;
    }

    return 1;
}

// функции модификации
void build_b(double B[], int m, double a, double x, double h)
{
    for (int i = 0; i < m; ++i){
        B[i] = 2.5 * sin(a * x + i * i * h);
    }
}

int remove_small(double B[], int m)
{
    int k = 0;
    for (int i = 0; i < m; ++i){
        if (fabs(B[i]) >= 0.7){
            B[k] = B[i];
            ++k;
        }
    }
    m = k;
    return m;
}

int insert_zero_first(double A[], int n)
{
    int pos = 0;

    if (n == CAPACITY){
        return -1;
    } else {
        for (int i = n; i > pos; --i){
            A[i]  = A[i - 1];
        }
    }
    A[pos] = 0;
    ++n;

    return n;
}

void replace_negative(double A[], int n)
{
    for (int i = 0; i < n; ++i){
        if (A[i] < 0){
            A[i] = 0;
        }
    }
}

// вывод 
void print_array(const double A[], int n)
{
    for (int i = 0; i < n; ++i){
        printf("%.3lf ", A[i]);
    }
    printf("\n");
}

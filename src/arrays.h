#ifndef ARRAYS_H
#define ARRAYS_H

#define CAPACITY 20

/* Ввод. Возвращают 0 при ошибке ввода. */
int read_array(double A[], int capacity);   /* длина n и n элементов; возвращает n */
int read_length(int capacity);              /* длина m; возвращает m */
int read_params(double p[]);                /* a, x, h в p[0], p[1], p[2]; возвращает 1 */

/* Модификация. Ничего не читают и не печатают. */
void build_b(double B[], int m, double a, double x, double h);
int remove_small(double B[], int m);        /* возвращает новую длину */
int insert_zero_first(double A[], int n);   /* новая длина или -1: нет места */
void replace_negative(double A[], int n);

/* Вывод. */
void print_array(const double A[], int n);

#endif
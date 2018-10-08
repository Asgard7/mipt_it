#include <stdio.h>
#include <stdlib.h>

typedef struct athlet { //структура представляющая атлета с массой m и силой n
    int m;
    int n;
} Athlet;

int cmp_n(const void *a, const void *b); //компаратор силы
int m_sum(Athlet *A, int n); //функция считающая общую массу заданного диапазона атлетов

void get_struct(Athlet *A, int k); //функция для получения массы и силы массива атлетов
void sort_struct_n(Athlet *A, int k); //функция для сортировки атлетов по силе
void print_struct(Athlet *A, int n); //ункция для печати заданного диапазона атлетов

int main() {
    int k, i = 0, s;
    scanf("%d", &k);
    Athlet A[k]; //создаем массив структур типа атлет
    get_struct(A, k);
    sort_struct_n(A, k);
    while (i < k) {
        s = m_sum(A, i);
        if (i == k - 1) {
            print_struct(A, i);
            return 0;
        } else if (s <= A[i + 1].n) {
            i++;
        } else {
            print_struct(A, i);
            return 0;
        }
    }
    return 0;
}

int cmp_n(const void *a, const void *b) {
    return (((Athlet *) a)->n - ((Athlet *) b)->n);
}

int m_sum(Athlet *A, int n) {
    int s = 0;
    for (int m = 0; m <= n; m++) {
        s = s + A[m].m;
    }
    return s;
}

void get_struct(Athlet *A, int k) {
    printf("Enter mass and force by space: ");
    for (int i = 0; i < k; i++)
        scanf("%d %d", &A[i].m, &A[i].n);
}

void sort_struct_n(Athlet *A, int k) {
    qsort(A, k, sizeof(A[0]), cmp_n);
}

void print_struct(Athlet *A, int n) {
    for (int i = 0; i <= n; i++)
        printf("%d - %d:%d\n", i, A[i].m, A[i].n); //печатает атлетов в столбик в виде №атлета - масса:сила
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define N 10
#define M 100

double calc_f(double val_x);
int task1();
int task2();

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    task1();
    task2();
    return 0;
}

int task1()
{
    float A[N], temp, sum = 0;

    printf("\nЗадание 1\n");
    printf("Введите %d вещественных чисел:\n", N);

    for (int i = 0; i < N; i++)
    {
        printf("A[%d] = ", i);
        if (scanf("%f", &A[i]) != 1)
        {
            printf("Ошибка ввода!\n");
            return 0;
        }
    }

    printf("\nИндекс | Исходное значение | Новое значение\n");
    for (int i = 0; i < N; i++)
    {
        temp = A[i];
        A[i] = A[i] * 2;
        sum += A[i];
        printf("%6d | %17.3f | %14.3f\n", i, temp, A[i]);
    }

    printf("\nСреднее арифметическое = %.3f\n", sum / N);
    return 0;
}

int task2()
{
    double B[M];
    double a = 0.1, b = 2.1;
    double step = (b - a) / (M - 1);
    double x, sum_pos = 0, sum_neg = 0, middle = 0;
    int count_pos = 0, count_neg = 0;

    printf("\nЗадание 2\n");

    for (int i = 0; i < M; i++)
    {
        x = a + i * step;
        B[i] = calc_f(x);
    }

    for (int i = 0; i < M; i++)
    {
        if (B[i] > 0)
        {
            sum_pos += B[i];
            count_pos++;
        }
        else if (B[i] < 0)
        {
            sum_neg += B[i];
            count_neg++;
        }
    }

    if (count_pos > 0)
        middle = sum_pos / count_pos;

    printf("Массив | Сумма (+) | Сумма (-) | Кол-во (+) | Кол-во (-) | Среднее (+)\n");
    printf("B      | %9.3f | %9.3f | %10d | %10d | %11.3f\n",
        sum_pos, sum_neg, count_pos, count_neg, middle);

    return 0;
}


double calc_f(double val_x)
{
    return val_x * val_x + sin(5 * val_x);
}

#include <stdio.h>

// Функция для сортировки трех вещественных чисел по указателям
void sort3(float *a, float *b, float *c) {
    float temp;

    // Сравниваем и меняем местами значения, чтобы отсортировать их
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
}

int main() {
    float x, y, z;

    // Ввод значений пользователем
    printf("Введите три вещественных числа: ");
    scanf("%f %f %f", &x, &y, &z);
    
    printf("До сортировки: x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
    
    sort3(&x, &y, &z);
    
    printf("После сортировки: x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
    
    return 0;
}

// Пример.
// Ввод: 8.12 3 6.66 Вывод: 3 6.66 8.12
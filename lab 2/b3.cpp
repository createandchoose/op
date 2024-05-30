#include <iostream>

void transform(char* s) {
    char replacement = 'a'; // Начинаем с буквы 'a'
    while (*s != '\0') {
        if (*s == '*') {
            *s = replacement; // Заменяем символ '*' на текущую букву
            ++replacement; // Переходим к следующей букве
        }
        ++s;
    }
}

int main() {
    char s[] = "doro*ro*hyak*kimar*u";
    transform(s);
    std::cout << "Transformed string: " << s << std::endl; // Должно вывести "doroarobhyakckimardu"
    return 0;
}

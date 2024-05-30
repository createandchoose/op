#include <iostream>
#include <cassert>
#define NDEBUG

using namespace std;

int wordcount(const char* s) {
    int count = 0;
    bool inWord = false;

    while (*s != '\0') {
        if (*s == ' ' || *s == '\t' || *s == '\n') {
            inWord = false;
        } else if (!inWord) {
            ++count;
            inWord = true;
        }
        ++s;
    }

    return count;
}

int main() {
    // Dulustan's tests
    {
        {
            char s[100] = "a bcd ef gg!";
            assert(wordcount(s) == 4);
        }
        
        {
            char s[100] = "captain, oh captain!!";
            assert(wordcount(s) == 3);
        }

        {
            char s[100] = "x xx xxx xxxxxxxxx x x x";    
            assert(wordcount(s) == 7);
        }

        cout << "SUCCESS!" << endl;
    }

    // Сделайте 3 теста
    // Student's tests
    {
        // Пользовательские тесты могут быть добавлены здесь
        char s1[100] = "Big Mom and Kaido are defeated!";
        cout << "Word count: " << wordcount(s1) << endl; // Должно вывести 6
        
        char s2[100] = "   ";
        cout << "Word count: " << wordcount(s2) << endl; // Должно вывести 0
        
        char s3[100] = "Hello\tworld\n";
        cout << "Word count: " << wordcount(s3) << endl; // Должно вывести 2
        
        cout << "SUCCESS!" << endl;
    }

    return 0;
}

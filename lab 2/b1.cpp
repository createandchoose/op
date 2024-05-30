#include <iostream>
#include <cassert>
#define NDEBUG

using namespace std;

const char* find_money(const char* s) {
    while (*s != '\0') {
        if (*s == 'm' && *(s + 1) == 'o' && *(s + 2) == 'n' && *(s + 3) == 'e' && *(s + 4) == 'y') {
            return s;
        }
        ++s;
    }
    return nullptr;
}

int main() {
    // Dulustan's tests
    {
        {
            char s[]{"thereisnomonyhere"};
            assert(find_money(s) == nullptr);
        }

        {
            char s[]{"woohoo, money!"};
            assert(find_money(s) == s + 8);
        }

        {
            char s[]{"wait, money here, money there, which one is correct?"};
            assert(find_money(s) == s + 6);
        }

        cout << "SUCCESS!" << endl;
    }

    // Сделайте 3 теста
    // Student's tests
    {
        {
            char s[]{"money is not everything"};
            assert(find_money(s) == s);
        }

        {
            char s[]{"I need more money"};
            assert(find_money(s) == s + 10);
        }

        {
            char s[]{"Where is the money?"};
            assert(find_money(s) == s + 12);
        }

        cout << "SUCCESS!" << endl;
    }

    return 0;
}

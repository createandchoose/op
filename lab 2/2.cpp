#include <iostream>
#include <cassert>
#define NDEBUG

using namespace std;

void fun(int* a) {
    int i = 0;
    while (a[i] != -1) {
        a[i] = (i + 1) * (i + 1);
        ++i;
    }
}

int main() {
    // Dulustan's tests
    {
        {
            int a[100000]{};
            a[25] = -1;
            fun(a);

            for (int i = 0; i < 25; ++i) {
                assert(a[i] == (i + 1) * (i + 1));
            }
        }

        {
            int a[100000]{};
            a[333] = -1;
            fun(a);

            for (int i = 0; i < 333; ++i) {
                assert(a[i] == (i + 1) * (i + 1));
            }
        }

        {
            int a[100000]{};
            a[2774] = -1;
            fun(a);

            for (int i = 0; i < 2774; ++i) {
                assert(a[i] == (i + 1) * (i + 1));
            }
        }

        cout << "SUCCESS!" << endl;
    }

    // Сделайте 3 теста
    // Student's tests
    {
        {
            int a[10]{};
            a[5] = -1;
            fun(a);

            for (int i = 0; i < 5; ++i) {
                assert(a[i] == (i + 1) * (i + 1));
            }
        }

        {
            int a[50]{};
            a[12] = -1;
            fun(a);

            for (int i = 0; i < 12; ++i) {
                assert(a[i] == (i + 1) * (i + 1));
            }
        }

        {
            int a[20]{};
            a[0] = -1;
            fun(a);

            assert(a[0] == -1);
        }

        cout << "SUCCESS!" << endl;
    }
}

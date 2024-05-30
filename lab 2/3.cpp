#include <iostream>
#include <cassert>
#define NDEBUG

using namespace std;

int range(int* a, int n) {
    if (n <= 0) {
        return 0; // Если размер массива меньше или равен 0, возвращаем 0
    }

    int* p = a;
    int minVal = *p;
    int maxVal = *p;

    for (int i = 1; i < n; ++i) {
        ++p;
        if (*p < minVal) {
            minVal = *p;
        }
        if (*p > maxVal) {
            maxVal = *p;
        }
    }

    return maxVal - minVal;
}

int main() {
    // Dulustan's tests
    {
        {
            int a[] = {1, 2, 3, 4, 5, 6, 7};
            assert(range(a, 7) == 6);
        }
        
        {
            int a[] = {-1, 99, -5, 4, 28, -99, 66, 0};
            assert(range(a, 8) == 198);
        }        

        {
            int a[] = {1000, 1000, 1000, 1000};
            assert(range(a, 4) == 0);
        }        

        cout << "SUCCESS!" << endl;
    }

    // Сделайте 3 теста
    // Student's tests
    {        
        {
            int a[] = {10, 20, 30, 40, 50};
            assert(range(a, 5) == 40);
        }

        {
            int a[] = {-10, -20, -30, -40, -50};
            assert(range(a, 5) == 40);
        }

        {
            int a[] = {5, 5, 5, 5, 5};
            assert(range(a, 5) == 0);
        }

        cout << "SUCCESS!" << endl;
    }

    return 0;
}

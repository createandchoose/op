#include <iostream>
#include <cassert>
#define NDEBUG

using namespace std;

bool is_pal(const double* a, int n) {
    const double* left = a;
    const double* right = a + n - 1;

    while (left < right) {
        if (*left != *right) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

int main() {
    // Dulustan's tests
    {
        {
            double a[]{1, 2, 3, 2, 1};        
            assert(is_pal(a, 5));
        }
        
        {
            double a[]{1, -2, 3, 4, 999, 4, 3, -2, 1};        
            assert(is_pal(a, 9));
        }
        
        {
            double a[]{1, 2, 3, 3, 1};        
            assert(!is_pal(a, 5));
        }
                
        {
            double a[]{-77, 23, 365, 366, 23, -77};        
            assert(!is_pal(a, 6)); 
        }        

        cout << "SUCCESS!" << endl;
    }

    // Сделайте 2 позитивных и 2 негативных теста
    // Student's tests
    {        
        {
            double a[]{5, 10, 15, 10, 5};
            assert(is_pal(a, 5));
        }

        {
            double a[]{123, 456, 789, 456, 123};
            assert(is_pal(a, 5));
        }

        {
            double a[]{1, 2, 3, 4, 5};
            assert(!is_pal(a, 5));
        }

        {
            double a[]{7, 8, 9, 8, 6};
            assert(!is_pal(a, 5));
        }

        cout << "SUCCESS!" << endl;
    }

    return 0;
}

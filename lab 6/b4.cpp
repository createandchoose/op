#include <iostream>
#include <vector>
#include <algorithm>

// Function to calculate the sum of digits of a number
int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Custom comparator
bool custom_comparator(int a, int b) {
    return sum_of_digits(a) < sum_of_digits(b);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // Sort using stable_sort with the custom comparator
    std::stable_sort(numbers.begin(), numbers.end(), custom_comparator);

    // Output the sorted numbers
    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

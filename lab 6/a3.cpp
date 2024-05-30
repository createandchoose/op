#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Функция для сортировки вставками по убыванию
void insertionSortDescending(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Вставляем arr[i] в отсортированную последовательность arr[0..i-1]
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Функция для проверки отсортированного массива по убыванию
bool check_sorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] < arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ifstream inputFile("multitest_1.txt");
    if (!inputFile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<int> arr;
        std::stringstream ss(line);  // Используем stringstream для разделения чисел
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        insertionSortDescending(arr);

        if (check_sorted(arr)) {
            std::cout << "Array is sorted in descending order." << std::endl;
        } else {
            std::cout << "Array is NOT sorted in descending order." << std::endl;
        }
    }

    inputFile.close();
    return 0;
}

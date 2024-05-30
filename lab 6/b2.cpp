#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

class SortingChampion {
public:
    // Selection Sort
    static void selection_sort(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n - 1; ++i) {
            int min_index = i;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < a[min_index]) {
                    min_index = j;
                }
            }
            swap(a[i], a[min_index]);
        }
    }

    // Bubble Sort
    static void bubble_sort(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                }
            }
        }
    }

    // Insertion Sort
    static void insertion_sort(vector<int>& a) {
        int n = a.size();
        for (int i = 1; i < n; ++i) {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                --j;
            }
            a[j + 1] = key;
        }
    }

    // Merge Sort
    static void merge_sort(vector<int>& a) {
        if (a.size() <= 1) return;
        merge_sort_recursive(a, 0, a.size() - 1);
    }

    // Quick Sort
    static void quick_sort(vector<int>& a) {
        quick_sort_recursive(a, 0, a.size() - 1);
    }

    // Randomized Quick Sort
    static void randomized_quick_sort(vector<int>& a) {
        srand(time(0));
        randomized_quick_sort_recursive(a, 0, a.size() - 1);
    }

private:
    // Helper functions for Merge Sort
    static void merge(vector<int>& a, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        vector<int> left(n1);
        vector<int> right(n2);
        for (int i = 0; i < n1; ++i)
            left[i] = a[l + i];
        for (int i = 0; i < n2; ++i)
            right[i] = a[m + 1 + i];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                a[k++] = left[i++];
            } else {
                a[k++] = right[j++];
            }
        }

        while (i < n1) {
            a[k++] = left[i++];
        }

        while (j < n2) {
            a[k++] = right[j++];
        }
    }

    static void merge_sort_recursive(vector<int>& a, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            merge_sort_recursive(a, l, m);
            merge_sort_recursive(a, m + 1, r);
            merge(a, l, m, r);
        }
    }

    // Helper functions for Quick Sort
    static int partition(vector<int>& a, int l, int r) {
        int pivot = a[(l + r) / 2];
        int i = l, j = r;
        while (i <= j) {
            while (a[i] < pivot) ++i;
            while (a[j] > pivot) --j;
            if (i <= j) {
                swap(a[i], a[j]);
                ++i;
                --j;
            }
        }
        return i;
    }

    static void quick_sort_recursive(vector<int>& a, int l, int r) {
        if (l < r) {
            int pi = partition(a, l, r);
            quick_sort_recursive(a, l, pi - 1);
            quick_sort_recursive(a, pi, r);
        }
    }

    // Helper functions for Randomized Quick Sort
    static int randomized_partition(vector<int>& a, int l, int r) {
        int random_index = l + rand() % (r - l + 1);
        swap(a[random_index], a[(l + r) / 2]);
        return partition(a, l, r);
    }

    static void randomized_quick_sort_recursive(vector<int>& a, int l, int r) {
        if (l < r) {
            int pi = randomized_partition(a, l, r);
            randomized_quick_sort_recursive(a, l, pi - 1);
            randomized_quick_sort_recursive(a, pi, r);
        }
    }
};

void run_tests(const string& input_file, const string& output_file, bool limited_algorithms = false) {
    ifstream infile(input_file);
    ofstream outfile(output_file);

    if (!infile) {
        cerr << "Error opening input file!" << endl;
        return;
    }

    if (!outfile) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    vector<void (*)(vector<int>&)> all_sorts = {
        SortingChampion::selection_sort,
        SortingChampion::bubble_sort,
        SortingChampion::insertion_sort,
        SortingChampion::merge_sort,
        SortingChampion::quick_sort,
        SortingChampion::randomized_quick_sort
    };

    vector<void (*)(vector<int>&)> limited_sorts = {
        SortingChampion::merge_sort,
        SortingChampion::quick_sort,
        SortingChampion::randomized_quick_sort
    };

    auto& sorts = limited_algorithms ? limited_sorts : all_sorts;
    vector<string> sort_names = {
        "Selection Sort",
        "Bubble Sort",
        "Insertion Sort",
        "Merge Sort",
        "Quick Sort",
        "Randomized Quick Sort"
    };

    vector<string> limited_sort_names = {
        "Merge Sort",
        "Quick Sort",
        "Randomized Quick Sort"
    };

    auto& sort_names_ref = limited_algorithms ? limited_sort_names : sort_names;

    int n;
    while (infile >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            infile >> a[i];
        }

        outfile << "Original array: ";
        for (const auto& num : a) {
            outfile << num << " ";
        }
        outfile << "\n";

        for (size_t i = 0; i < sorts.size(); ++i) {
            vector<int> b = a;
            auto start = high_resolution_clock::now();
            sorts[i](b);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start).count();

            outfile << sort_names_ref[i] << " sorted array: ";
            for (const auto& num : b) {
                outfile << num << " ";
            }
            outfile << "\n";

            outfile << sort_names_ref[i] << " took " << duration << " milliseconds.\n";
        }
        outfile << "\n";
    }
}

int main() {
    run_tests("multitest_1.txt", "report_1.txt");
    run_tests("multitest_2.txt", "report_2.txt", true);
    return 0;
}

/* 8. Implement Parallel bubble sort using OpenMP */

#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void parallelBubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped = true;

    #pragma omp parallel
    {
        while (swapped) {
            swapped = false;

            #pragma omp for
            for (int i = 0; i < n - 1; ++i) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
        }
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 1, 2, 7, 4, 6};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform parallel bubble sort
    parallelBubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

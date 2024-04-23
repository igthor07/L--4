/* 10 . Implement min, max using parallel reduction */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void parallelMinMax(const vector<int>& arr, int& globalMin, int& globalMax) {
    int localMin = arr[0];
    int localMax = arr[0];

    // Find local min and max
    for (size_t i = 1; i < arr.size(); ++i) {
        localMin = min(localMin, arr[i]);
        localMax = max(localMax, arr[i]);
    }

    globalMin = localMin;
    globalMax = localMax;
}

int main() {
    vector<int> arr = {7, 3, 9, 1, 6, 5, 2, 8, 4};

    int globalMin, globalMax;

    // Compute min and max using parallel reduction
    parallelMinMax(arr, globalMin, globalMax);

    cout << "Min: " << globalMin << endl;
    cout << "Max: " << globalMax << endl;

    return 0;
}

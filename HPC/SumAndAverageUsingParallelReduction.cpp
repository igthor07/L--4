#include <iostream>
#include <vector>

using namespace std;

void parallelSumAndAverage(const vector<int>& arr, int& sum, double& average) {
    int localSum = 0;

    // Calculate local sum
    for (int num : arr) {
        localSum += num;
    }

    // Reduce local sums to obtain global sum
    sum = localSum;

    // Calculate average
    average = static_cast<double>(sum) / arr.size();
}

int main() {
    vector<int> arr = {7, 3, 9, 1, 6, 5, 2, 8, 4};

    int globalSum;
    double globalAverage;

    // Compute sum and average using parallel reduction
    parallelSumAndAverage(arr, globalSum, globalAverage);

    cout << "Sum: " << globalSum << endl;
    cout << "Average: " << globalAverage << endl;

    return 0;
}

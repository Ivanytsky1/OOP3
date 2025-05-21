#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for accumulate

using namespace std;

int main() {
    // Input array
    vector<int> arr = { 3, -5, 7, -2, 10, -8, 1, 4 };

    // 1. Sum of negative elements
    int sumNegatives = accumulate(arr.begin(), arr.end(), 0,
        [](int sum, int val) {
            return val < 0 ? sum + val : sum;
        });
    cout << "Sum of negative elements: " << sumNegatives << endl;

    // 2. Product between min and max (excluding them)gia()
    auto something = arr.begin();
    auto minIt = min_element(arr.begin(), arr.end());
    auto maxIt = max_element(arr.begin(), arr.end());

    // Ensure left to right iteration
    auto start = min(minIt, maxIt) + 1;
    auto end = max(minIt, maxIt);

    int product = 1;
    if (start < end) {
        product = accumulate(start, end, 1, multiplies<int>());
    }
    else {
        product = 0;
    }
    cout << "Product between min and max: " << product << endl;

    // 3. Sort in ascending order
    sort(arr.begin(), arr.end());
    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

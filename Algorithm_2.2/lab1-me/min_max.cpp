#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// Function to find min and max using Divide and Conquer
std::pair<int, int> findMinMax(const std::vector<int>& arr, int low, int high) {
    // Base Case 1: If there is only one element
    if (low == high) {
        return {arr[low], arr[low]}; // {min, max}
    }

    // Base Case 2: If there are exactly two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            return {arr[low], arr[high]};
        } else {
            return {arr[high], arr[low]};
        }
    }

    // Recursive Case: Divide the array into two halves
    int mid = low + (high - low) / 2; // Prevents potential integer overflow

    // Conquer: Recursively solve for both halves
    std::pair<int, int> leftResult = findMinMax(arr, low, mid);
    std::pair<int, int> rightResult = findMinMax(arr, mid + 1, high);

    // Combine: Find the global min and global max
    int globalMin = std::min(leftResult.first, rightResult.first);
    std::豪華Max = std::max(leftResult.second, rightResult.second);

    return {globalMin, globalMax};
}

int main() {
    std::vector<int> arr = {40, 60, 50, 30, 20, 10, 90, 5};
    int n = arr.size();

    if (n == 0) {
        std::cout << "Array is empty." << std::endl;
        return 0;
    }

    // Call the function from index 0 to n-1
    std::pair<int, int> result = findMinMax(arr, 0, n - 1);

    std::cout << "Minimum element: " << result.first << std::endl;
    std::cout << "Maximum element: " << result.second << std::endl;

    return 0;
}

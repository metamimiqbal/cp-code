#include <bits/stdc++.h>
using namespace std;

// Partition
int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);

    return i + 1;
}

// Divide and Conquer
void quick_sort(vector<int> &vec, int low, int high) {
    if (low >= high)
        return;

    int pivot_index = partition(vec, low, high);

    quick_sort(vec, low, pivot_index - 1);
    quick_sort(vec, pivot_index + 1, high);
}

int main() {
    vector<int> vec = {5, 8, 1, 3, 7, 2, 4, 6};

    quick_sort(vec, 0, vec.size() - 1);

    for (int x : vec)
        cout << x << " ";
    cout << '\n';

    return 0;
} 
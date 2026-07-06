#include <bits/stdc++.h>
using namespace std;

int partition (int arr[], int p, int r) {
    int x = arr[r];
    int i = p-1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[p],arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quick_sort(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }
}

int main() {
    int arr[] = {159, 152, 177, 172, 174};
    quick_sort(arr, 0, 5);
    for (auto i : arr) {
        cout << i << " ";
    }
}
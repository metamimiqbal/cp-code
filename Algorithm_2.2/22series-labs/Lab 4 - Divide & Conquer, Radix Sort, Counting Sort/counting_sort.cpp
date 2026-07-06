#include <bits/stdc++.h>
using namespace std;

void counting (int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    int cnt[max + 1];
    for (int i = 0; i <= max; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        cnt[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        cnt[i] += cnt[i-1];
    }
    int out[size];
    for (int i = size-1; i >= 0; i--) {
        out[cnt[arr[i]]-1] = arr[i];
        cnt[arr[i]]--;
    }
    for (int i = 0; i < size; i++) {
        cout << out[i] << " ";
    }
}

int main() {
    int arr[8] = {0, 2, 5, 2, 7, 7, 3, 5};
    counting(arr, 8);
}
#include <bits/stdc++.h>
using namespace std;

void counting (int arr[], int size, int n) {
    int p = pow(10,n);
    int max = (arr[0]/p)%10;
    for (int i = 1; i < size; i++) {
        if ((arr[i]/p)%10 > max) max = (arr[i]/p)%10;
    }
    int cnt[max + 1];
    for (int i = 0; i <= max; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        cnt[(arr[i]/p)%10]++;
    }
    for (int i = 1; i <= max; i++) {
        cnt[i] += cnt[i-1];
    }
    int out[size];
    for (int i = size-1; i >= 0; i--) {
        out[cnt[(arr[i]/p)%10]-1] = arr[i];
        cnt[(arr[i]/p)%10]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = out[i];
    }
}

void radix (int arr[], int size) {
    int max = -1;
    for (int i = 0; i < size; i++) {
        max = (arr[i] > max) ? arr[i] : max;
    }
    for (int i = 0; max; i++) {
        counting(arr,size,i);
        max/=10;
    }
}

int main() {
    int arr[8] = {776, 270, 669, 354, 960, 652, 261, 77};
    radix(arr, 8);
    for (auto i : arr) cout << i << " ";
}
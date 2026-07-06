#include <bits/stdc++.h>
using namespace std;

int max_dnc(int arr[], int l, int r) {
    if (r-l < 2) { // 1 or 2 elements
        return max(arr[l], arr[r]);
    } else {
        int m = (l+r)/2;
        return max(max_dnc(arr, l, m), max_dnc(arr, m+1, r));
    }
}

int main() {
    int arr[8] = {0, 9, 4, 2, 1, 7};
    cout << "Maximum: " << max_dnc(arr, 0, 5) << endl;
}
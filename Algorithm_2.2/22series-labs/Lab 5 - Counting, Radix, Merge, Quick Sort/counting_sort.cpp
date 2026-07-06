#include <bits/stdc++.h>
using namespace std;

void counting (int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {             // finding max
        if (arr[i] > max) max = arr[i];
    }
    int cnt[max + 1];
    for (int i = 0; i <= max; i++) {             // initialize cnt[] with zeros
        cnt[i] = 0;
    }
    for (int i = 0; i < size; i++) {             // count the frequencies of input array numbers
        cnt[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {             // prefix sum
        cnt[i] += cnt[i-1];
    }
    int out[size];
    for (int i = size-1; i >= 0; i--) {          // placing number in appropriate positions in out[]
        out[cnt[arr[i]]-1] = arr[i];
        cnt[arr[i]]--;
    }
    for (int i = 0; i < size; i++) {             // printing out[]
        cout << out[i] << " ";
    }
}

int main() {
    int arr[8] = {0, 2, 5, 2, 7, 7, 3, 5};
    counting(arr, 8);
}
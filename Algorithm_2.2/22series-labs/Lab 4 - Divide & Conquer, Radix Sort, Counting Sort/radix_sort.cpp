#include <bits/stdc++.h>
using namespace std;

void selection1 (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[j]%10 < arr[i]%10) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void selection2 (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if ((arr[j]%100)/10 < (arr[i]%100)/10) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void selection3 (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[j]/100 < arr[i]/100) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void radix (int arr[], int size) {
    selection1(arr, 8);
    selection2(arr, 8);
    selection3(arr, 8);
}

int main() {
    int arr[8] = {776, 270, 669, 354, 960, 652, 261, 77};
    radix(arr, 8);
    for (auto i : arr) cout << i << " ";
}
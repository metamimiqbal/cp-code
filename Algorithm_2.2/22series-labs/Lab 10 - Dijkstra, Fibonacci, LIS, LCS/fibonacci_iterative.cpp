#include <bits/stdc++.h>
using namespace std;

int arr[100];

int main() {
    for (int i = 0; i < 100; i++) arr[i] = -1;
    
    cout << "Which fibonacci number: ";
    int n; cin >> n;

    arr[0] = 0; arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << n << "th fibonacci number: " << arr[n] << endl;
}
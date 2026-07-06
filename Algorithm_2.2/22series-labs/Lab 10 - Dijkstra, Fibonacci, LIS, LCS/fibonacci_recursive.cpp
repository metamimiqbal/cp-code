#include <bits/stdc++.h>
using namespace std;

int arr[100];
int n;

int fibo (int n) {
    if (arr[n] != -1) {
        return arr[n];
    }

    if (n == 0) {
        arr[n] = 0;
        return arr[n];
    } else if (n == 1) {
        arr[n] = 1;
        return arr[n];
    } else {
        arr[n] = fibo(n-1) + fibo(n-2);
        return arr[n];
    }
}

int main() {
    for (int i = 0; i < 100; i++) arr[i] = -1;
    
    cout << "Which fibonacci number: "; cin >> n;

    cout << n << "th fibonacci number: " << fibo(n) << endl;
}
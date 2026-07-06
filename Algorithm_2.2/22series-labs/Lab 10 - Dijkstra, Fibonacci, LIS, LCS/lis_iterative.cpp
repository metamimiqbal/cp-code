#include <bits/stdc++.h>
using namespace std;

int store[100];

int lis (int i, int s[], int size) {
    if (store[i] != -1) return store[i];

    int var = 1;
    for (int j = i+1; j < size; j++) {
        if (s[i] < s[j]) {
            var = max(1 + lis(j,s,size), var);
        }
    }

    return store[i] = var;
}

int main() {
    int size = 6;
    int s[size] = {1,7,9,5,13,8};

    for (int i = 0; i < 100; i++)
        store[i] = 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] > s[j]) {
                store[i] = max(store[i], store[j]+1);
            }
        }
    }

    int m = -1;
    for (int i = 0; i < size; i++) {
        m = max(m, store[i]);
    }

    cout << "Largest Increasing Subsequence: " << m << endl;    
}
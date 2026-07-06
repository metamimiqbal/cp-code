#include <bits/stdc++.h>
using namespace std;

int store[100][100];

int lcs (int i, int j, string s, string w) {
    if (i >= s.length() || j >= w.length()) return 0;

    if (s[i] == w[j]) {
        if (store[i][j] == -1) {
            store[i][j] = 1 + lcs(i+1, j+1, s, w);
            return store[i][j];
        } else return store[i][j];
    } else {
        if (store[i][j] == -1) {
            store[i][j] = max(lcs(i+1,j,s,w), lcs(i,j+1,s,w));
            return store[i][j];
        } else return store[i][j];
    }
}

int main() {
    string s = {'a','b','c','d','e'};
    string w = {'b','d','e'};

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            store[i][j] = -1;

    cout << "Largest Common Subsequence: " << lcs(0,0,s,w) << endl;    
}
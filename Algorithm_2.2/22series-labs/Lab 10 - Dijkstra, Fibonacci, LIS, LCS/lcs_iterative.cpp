#include <bits/stdc++.h>
using namespace std;

int store[100][100];

int main() {
    string s = {'a','b','c','d','e'};
    string w = {'b','d','e'};

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            store[i][j] = 0;

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= w.length(); j++) {
            if (s[i-1] == w[j-1]) {
                store[i][j] = 1 + store[i-1][j-1];
            } else {
                store[i][j] = max(store[i-1][j], store[i][j-1]);
            }
        }
    }
    
    cout << "Largest Common Subsequence: " << store[s.length()][w.length()] << endl;
}
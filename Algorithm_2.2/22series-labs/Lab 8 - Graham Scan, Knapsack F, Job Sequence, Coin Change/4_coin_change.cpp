#include <bits/stdc++.h>
using namespace std;

bool comp (pair<int,int> p1, pair<int,int> p2) {
    if (p1.first > p2.first) return true;
    else return false;
}

int main() {
    cout << "Enter the amount (<=100): ";
    int a; cin >> a;
    int coins[] = {1, 2, 5, 10, 20, 50, 100};
    int num[] = {0,0,0,0,0,0,0};
    int i = 6;
    while (a) {
        if ((a - coins[i]) < 0) i--;
        else {
            a -= coins[i];
            num[i]++;
        }
    }
    cout << "Number of coins needed: " << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Coin " << coins[i] << ": " << num[i] << endl;
    }
}
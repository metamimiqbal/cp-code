#include <bits/stdc++.h>
using namespace std;

int main() {
    /*
              5
           /     \
          2       3
         / \     / \
        4   1   7   6
    */

    vector<vector<int>> v;
    vector<int> x;
    x.push_back(5);
    x.push_back(2);
    x.push_back(3);
    v.push_back(x);

    x.clear();
    x.push_back(4);
    x.push_back(1);
    v.push_back(x);

    x.clear();
    x.push_back(7);
    x.push_back(6);
    v.push_back(x);

    int arr[7];
    int j = 0;
    for (auto i : v) {
        for (auto k : i) {
            arr[j++] = k;
        }
    }

    for (auto i : arr) {
        cout << i << " ";
    }
}
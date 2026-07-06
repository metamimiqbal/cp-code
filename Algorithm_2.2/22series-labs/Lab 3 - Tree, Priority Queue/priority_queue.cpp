#include <bits/stdc++.h>
using namespace std;

bool comp (pair<int,int> a, pair<int,int> b) {
    if (a.second < b.second)
        return true;
    else
        return false;
}

int main() {
    vector<pair<int,int>> v;
    v.push_back({1, 5});
    v.push_back({2, 2});
    v.push_back({3, 3});
    v.push_back({4, 4});
    v.push_back({5, 1});
    v.push_back({6, 7});
    v.push_back({7, 6});

    /*
              5
           /     \
          2       3
         / \     / \
        4   1   7   6
    */

    sort(v.begin(), v.end(), comp);
    for (auto i : v) cout << i.first << " ";
}
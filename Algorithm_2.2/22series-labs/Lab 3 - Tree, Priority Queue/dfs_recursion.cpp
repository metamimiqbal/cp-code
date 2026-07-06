#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(8);
void dfs(vector<vector<int>> &v, int p) {
    vis[p] = true; cout << p << " ";
    for (auto i : v[p]) {
        if (!vis[i]) {
            dfs(v, i);
        }
    }
}

int main() {
    /*
              5
           /     \
          2       3
         / \     / \
        4   1   7   6
    */

    vector<vector<int>> v(8);
    v[5].push_back(2);
    v[5].push_back(3);

    v[2].push_back(4);
    v[2].push_back(1);
    v[2].push_back(5);

    v[3].push_back(7);
    v[3].push_back(6);
    v[3].push_back(5);

    dfs(v, 5);
}
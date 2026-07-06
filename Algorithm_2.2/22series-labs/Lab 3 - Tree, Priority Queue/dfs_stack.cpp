#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> v) {
    stack<int> q;
    vector<bool> vis(8);

    q.push(5); vis[5] = true;
    while (!q.empty()) {
        int x = q.top();
        cout << x << " "; q.pop();
        for (auto i : v[x]) {    
            if (!vis[i]) {
                q.push(i);
                vis[i] = true;
            }
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

    dfs(v);
}
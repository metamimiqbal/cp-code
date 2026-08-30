#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define flt long double
#define VEC vector<ll>
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define rrep(i, a, b) for(ll i = (a); i>=(b); --i)
#define each(x, a) for(auto &x: (a))

vector<ll> bfs(vector<vector<ll>>&adj, ll start) {
    vector<ll>visited(9, 0);
    vector<ll>bfsv;
    queue<ll>que;
    que.push(start);
    visited[start] = 1;
    bfsv.push_back(start);

    while(!que.empty()) {
        ll node = que.front();
        que.pop();
        for(auto neighbor: adj[node]) {
            if(!visited[neighbor]) {
                que.push(neighbor);       
                visited[neighbor] = 1;
                bfsv.push_back(neighbor);
            }
        }
    }
    return bfsv;
}


void dfs(vector<vector<ll>>&adj, ll node, vector<ll>&visited, vector<ll>&dfsv) {
    dfsv.push_back(node);
    visited[node] = 1;
    for(auto neighbor: adj[node]) {
        if(!visited[neighbor]) {
            dfs(adj, neighbor, visited, dfsv);
        }
    }
}

int main() {
    vector<vector<ll>>adj{
        {}, {2, 6}, {1, 3, 4}, {2}, {2, 5}, {4, 8}, {1, 7, 9}, {6, 8}, {5, 7}, {6}
    };


    vector<ll>visited(9, 0);
    vector<ll>dfsv;
    dfs(adj, 1, visited, dfsv);
    for(auto x: dfsv) cout<<x<<" ";
    cout<<endl<<endl;
}


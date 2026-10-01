#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(ll i = (a); i < (b); ++i)
#define each(x, a) for(auto &x : (a))
#define nl "\n"
#define spc " "

vector<ll> parent(1e6 + 5);
vector<ll> rank_value(1e6 + 5);

void makeSet(ll n) {
    rep(i, 1, n + 1) {
        parent[i] = i;
        rank_value[i] = 0;
    }
}

ll findSet(ll n) {
    if(n == parent[n]) return n;
    return findSet(parent[n]);
}

bool unionSet(ll a, ll b) {
    ll x = findSet(a);
    ll y = findSet(b);
    if(x == y) return false;
    if(rank_value[x] < rank_value[y])
        parent[x] = y;
    else if(rank_value[x] > rank_value[y])
        parent[y] = x;
    else {
        parent[x] = y;
        rank_value[y]++;
    }
    return true;
}

int main() {
    cout<<"Input:\n";
    ll n, m;
    cin >> n >> m;
    makeSet(n);
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<tuple<ll, ll, ll>> edges;

    rep(i, 0, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, u, v});
    }
    sort(all(edges));
    ll totalCost = 0, taken = 0;
    vector<tuple<ll, ll, ll>> mst;
    each(e, edges) {
        ll w = get<0>(e);
        ll u = get<1>(e);
        ll v = get<2>(e);

        if(unionSet(u, v)) {

            totalCost += w;
            taken++;

            mst.push_back(e);

            if(taken == n - 1)
                break;
        }
    }

    cout<<"Output:\n";
    if(taken < n - 1) {
        cout << "graph is disconnected, no spanning tree\n";
    }
    else {
        cout << totalCost << nl;

        each(e, mst)
            cout << get<1>(e) << spc << get<2>(e) << spc << get<0>(e) << nl;
    }

    return 0;
}


/*
6 9
1 2 4
1 3 2
1 4 7
2 3 1
2 5 5
3 4 8
3 5 10
4 6 3
5 6 6
*/

/*
output:
17
2 3 1
1 3 2
4 6 3
2 5 5
5 6 6
*/
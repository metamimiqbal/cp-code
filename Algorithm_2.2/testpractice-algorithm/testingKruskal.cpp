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

vector<ll>parent(1e6+5);
vector<ll>putrank(1e6+5);

void makeSet(ll n) {
    rep(i, 1, n+1) {
        parent[i] = i;
        putrank[i] = 0;
    }
}

ll findSet(ll n) {
    if(parent[n] == n) return n;
    return findSet(parent[n]);
}

bool unionSet(ll a, ll b) {
    ll x = findSet(a);
    ll y = findSet(b);
    if(x == y) return false;

    if(putrank[x] < putrank[y]) {
        parent[x] = y;
    } else if(putrank[x] > putrank[y]) {
        parent[y] = x;
    } else {
        parent[x] = y;
        putrank[y]++;
    }
    return true;
}


int main() {
    ll n, m; cin>>n>>m;
    makeSet(n);
    vector<vector<pair<ll, ll>>> adj(n+1);
    vector<tuple<ll, ll, ll>>edges;
    // vector<tuple<ll, ll, ll>>ans;
    rep(i, 0, m) {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, u, v});
    }        
    sort(all(edges));

    ll cst = 0, taken = 0;
    vector<tuple<ll, ll, ll>>ans;

    for(auto e: edges) {
        ll u = get<0>(e);
        ll v = get<1>(e);
        ll w = get<2>(e);

        if(unionSet(v, w)) {
            taken++;
            cst += u;
            ans.push_back(e);
            if(taken == n-1) break;
        }
    }

    // if(taken < n-1) {
    //     cout<<"hynay\n"; 
    // } else {
    //     cout<<cst<<nl;
    //     for(auto e: edges) {
    //         cout<<get<0>e
    //     }
    // }
}


#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define THINK_LIKE_JACK_SPARROW FAST_IO

#define ll long long
#define VEC vector<ll>

#define all(x)  (x).begin(), (x).end()
#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define each(x, a) for(auto &x: (a))

#define MAX(x) *max_element(all(x))

#define nl '\n'


void solve() {
    ll n, m; cin>>n>>m;
    vector<VEC> adj(n+1);
    VEC indeg(n+1, 0), dp(n+1, 0);
    rep(i, 0, m) {
        ll x, y; cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }

    queue<ll> q;
    rep(i, 1, n+1) {
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        ll u = q.front(); q.pop();
        each(v, adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if(--indeg[v] == 0) q.push(v);
        }
    }

    cout<<MAX(dp)<<nl;
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    solve();

    return 0;
}
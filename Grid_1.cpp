#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define THINK_LIKE_JACK_SPARROW FAST_IO

#define ll long long
#define VEC vector<ll>

#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define each(x, a) for(auto &x: (a))

#define nl '\n'

constexpr ll MOD = 1000000007LL;


void solve() {
    ll h, w; cin>>h>>w;
    vector<string> g(h);
    each(s, g) cin>>s;

    vector<VEC> dp(h, VEC(w, 0));
    dp[0][0] = 1;
    rep(i, 0, h) {
        rep(j, 0, w) {
            if(g[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }

    cout<<dp[h-1][w-1]<<nl;
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    solve();

    return 0;
}
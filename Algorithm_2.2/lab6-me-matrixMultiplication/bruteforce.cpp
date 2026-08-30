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

int main() {
    ll n = 3;
    vector<vector<ll>>v1{{1, 2, 3}, {2, 3, 4}, {3, 4, 5}}, v2{{1, 2, 3}, {2, 3, 4}, {3, 4, 5}}, rslt(n, vector<ll>(n));

    rep(i, 0, n) {
        rep(j, 0, n) {
            rep(k, 0, n) {
                rslt[i][j] += v1[i][k] * v2[k][j];
            }
        }
    }

    for(auto u: rslt) {
        for(auto x: u) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

}

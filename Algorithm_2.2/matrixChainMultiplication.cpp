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

ll MCM(vector<ll>vec, ll i, ll j) {
    if(i+1==j) {
        return 0;
    }
    ll res = LLONG_MAX;
    for(ll k = i+1; k<j; k++) {
        ll curr = MCM(vec, i, k) + MCM(vec, k, j) + vec[i]*vec[k]*vec[j];
        res = min(res, curr);
    }

    return res;
}


int main() {
    ll n; cin>>n;
    VEC vec(n);
    rep(i, 0, n) cin>>vec[i];
    
    cout<<MCM(vec, 0, n-1)<<endl;
}


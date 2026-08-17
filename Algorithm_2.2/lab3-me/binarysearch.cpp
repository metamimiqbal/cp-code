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


ll peak(VEC &vec) {
    ll n = vec.size();
    if(n == 1) return vec[0];
    else if(vec[n-1] > vec[n-2]) return vec[n-1];
    else if(vec[0] > vec[1]) return vec[0];

    ll l = 1, r = n-2;
    while(l<=r) {
        ll md = l + (r-l)/2;

        if(vec[md] > vec[md-1] && vec[md] > vec[md+1])  return vec[md];
        else if(vec[md] > vec[md-1]) l = md + 1;
        else r = md - 1; 
    }
    return -1;
}



int main() {
    ll n; cin>>n;
    VEC arr(n);
    rep(i, 0, n) cin>>arr[i];
    cout<<peak(arr)<<endl;
}


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

ll numberOfRotation(VEC &vec) {
    ll l = 0, r = vec.size()-1;
    ll ans = LLONG_MAX;
    ll idx = -1;
    while(l<=r) {
        ll md = l + (r-l)/2;
        if(vec[l] <= vec[md]) { // sorted left half
            if(vec[l] < ans) {
                ans = vec[l], idx = l;
            }
            l = md + 1; // to go for the other half even though unsorted.
        } else { // if left half isn't sorted, then obviously the other right half is sorted.
            if(vec[md] < ans) {
                ans = vec[md], idx = md;
            }
            r = md - 1;
        }
    }
    return idx;
}



int main() {
    ll n; cin>>n;
    VEC arr(n);
    rep(i, 0, n) cin>>arr[i];
    cout<<numberOfRotation(arr)<<endl;
}


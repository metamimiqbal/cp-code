// homework:
// max_element, min_max both, merge sort -> lab report.


#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>vec {5, 4, 3, 2, 1};
ll mx(ll l, ll r) {
    if(l == r) return vec[l];
    ll md = (l+r)/2;
    return max(mx(l, md), mx(md+1, r));
}
ll mn(ll l, ll r) {
    if(l == r) return vec[l];
    ll md = (l+r)/2;
    return min(mn(l, md), mn(md+1, r));
}

pair<ll, ll> min_max(ll l, ll r) {
    if(l == r) return {vec[l], vec[l]};
    ll md = (l+r)/2;

    ll lf = min_max(l, md);
    ll rt = min_max(md+1, r);

    return {min(lf, rt), max(lf, rt)};
}


int main() {

    cout<<mn(0, 5)<<" "<<mx(0, 5)<<endl;


    return 0;
}
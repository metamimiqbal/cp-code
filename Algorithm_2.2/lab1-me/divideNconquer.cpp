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
vector<ll>vec {5, 4, 3, 2, 1};
pair<ll, ll> min_max(ll l, ll r) {
    if(l == r) return {vec[l], vec[l]};
    ll md = (l+r)/2;

    pair<ll, ll> lf = min_max(l, md);
    pair<ll, ll> rt = min_max(md+1, r);

    return {min(lf.first, rt.first), max(lf.second, rt.second)};
}


int main() {
    cout<<"Minimum: "<<min_max(0, 5).first<<"\nMaximum: "<<min_max(0, 5).second<<endl;
    return 0;
}
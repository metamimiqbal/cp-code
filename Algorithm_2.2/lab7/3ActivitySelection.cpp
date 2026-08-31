#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define flt long double
#define VEC vector<ll>
#define all(x)  (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define rrep(i, a, b) for(ll i = (a); i>=(b); --i)
#define each(x, a) for(auto &x: (a))
VEC activity_selection(ll activities, VEC &start, VEC &finish) {
    vector<pair<ll, ll>> a;
    rep(i, 0, activities) {
        a.push_back({finish[i], i});
    }
    sort(all(a));
    VEC selected;
    ll lastFinish = LLONG_MIN;
    each(x, a) {
        ll i = x.second;
        if(start[i] >= lastFinish) {
            selected.push_back(i);
            lastFinish = finish[i];
        }
    }
    return selected;
}
int main() {
    ll activities; cin>>activities;
    VEC start(activities), finish(activities);
    for(auto &u: start) cin>>u;
    for(auto &u: finish) cin>>u;
    VEC selected = activity_selection(activities, start, finish);
    cout<<"Selected Activities: ";
    for(auto u: selected) cout<<u<<" ";
    cout<<endl;
}
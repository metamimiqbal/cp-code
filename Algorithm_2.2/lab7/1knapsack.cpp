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

pair<vector<flt>, flt> fractional_knapsack(ll items, VEC &weight, VEC &value, ll capacity) {
    vector<pair<flt, ll>> ratio;
    vector<flt> fraction(items);
    rep(i, 0, items) {
        ratio.push_back({(flt)value[i]/weight[i], i});
    }
    sort(rall(ratio));
    ll remaining = capacity;
    flt totalValue = 0;
    rep(i, 0, items) {
        ll j = ratio[i].second;
        if(remaining == 0) break;
        else if(weight[j] <= remaining) fraction[j] = 1;
        else fraction[j] = (flt)remaining/weight[j];
        ll takenWeight = fraction[j]*weight[j];
        flt gainedValue = fraction[j] * value[j];
        remaining -= takenWeight;
        totalValue += gainedValue;
    }
    return {fraction, totalValue};
}

int main() {
    ll items, capacity; cin>>items>>capacity;
    VEC weight(items), value(items);
    for(auto &u: weight) cin>>u;
    for(auto &u: value) cin>>u;
    pair<vector<flt>, flt> vpl = fractional_knapsack(items, weight, value, capacity);
    cout<<"total Value: "<<vpl.second<<endl;
    vector<flt> v = vpl.first;
    for(auto u: v) cout<<u<<" ";
    cout<<endl;
}
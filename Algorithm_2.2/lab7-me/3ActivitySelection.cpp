// Activity Selection
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define nl '\n'

void solve(){
    ll n;cin>>n;
    ll nn = n;
    vector<pair<ll,ll>>vpr;
    while(n--){
        ll s,e;cin>>s>>e;
        vpr.push_back({e,s});
    }
    cout<<"Output: ";
    sort(all(vpr));
    ll cn = 1,sorbosesMovie = vpr[0].first;
    rep(i,1,nn){
        if(vpr[i].second>=sorbosesMovie){
            ++cn;
            sorbosesMovie=vpr[i].first;
        }
    }
    cout<<cn<<nl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
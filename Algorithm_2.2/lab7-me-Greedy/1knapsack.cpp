// fractional knapsack
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)

void solve(){
    int n;double c;cin>>n>>c;
    vector<double>w(n),p(n);
    for(auto &u:w)cin>>u;
    vector<double>fraction;
    ll i = 0;
    for(auto &u:p){
        cin>>u;
        fraction.push_back(u/w[i++]);
    }
    vector<pair<double,double>>vpr;
    rep(i,0,n)vpr.push_back({fraction[i],w[i]});
    sort(rall(vpr));
    double cost = 0;
    rep(i,0,n){
        double wt=vpr[i].second;
        double cst=vpr[i].first;
        if(c>0){
            if(c>wt){
                cost+=(wt*cst);
                c-=wt;
            }else{
                cost+=(c*cst);
                c=0;
            }
        }else break;
    }
    cout<<(ll)round(cost)<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;cin>>tt;while(tt--)
    solve();
    return 0;
}
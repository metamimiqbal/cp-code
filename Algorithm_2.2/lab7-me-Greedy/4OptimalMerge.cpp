// optimal merge
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(),(x).end()
#define VEC vector<ll>

void solve(){
    ll n;cin>>n;
    VEC a(n);
    for(auto &u:a)cin>>u;
    sort(all(a));
    ll ans = 0,sizing = 0;
    while(a.size()>1){
        sizing=a[0]+a[1];
        a.erase(a.begin(),a.begin()+2);
        a.push_back(sizing);
        ans+=(sizing-1);
        sort(all(a));
    }
    cout<<"Minimum total merging Cost: ";
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;cin>>tt;while(tt--)
    solve();
    return 0;
}
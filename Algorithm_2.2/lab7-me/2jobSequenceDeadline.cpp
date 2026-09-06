// Job Sequencing with Deadlines
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define spc " "
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)

void solve(){
    ll n;cin>>n;
    vector<tuple<ll,ll,ll>>vtpl;
    ll mxDeadline = -1;
    rep(i,0,n){
        ll id,ddln,mrk;
        cin>>id>>ddln>>mrk;
        mxDeadline=max(mxDeadline,ddln);
        vtpl.push_back({mrk,ddln,id});
    }
    cout<<"Output: ";
    sort(rall(vtpl));
    vector<ll>slot(mxDeadline+1);
    ll mark = 0;
    for(int i=0;i<n;i++){
        ll dedline=get<1>(vtpl[i]);
        while(slot[dedline]!=0 and dedline>0)dedline--;
        if(dedline>0){
            mark+=get<0>(vtpl[i]);
            slot[dedline]=get<2>(vtpl[i]);
        }
    }
    for(int i=1;i<=mxDeadline;i++){
        if(slot[i]!=0) cout<<slot[i]<<spc;
    }
    cout<<'\n'<<mark<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
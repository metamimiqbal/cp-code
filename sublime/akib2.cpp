/**
 *  created:  30/04/2026 08:53:38
**/
#include <bits/stdc++.h>
using namespace std;
#define optimize ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
#define vll vector<ll>
#define f(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define all(a) a.begin(),a.end()
#define swal  cout<<"YES"<<'\n';
#define hin cout<<"NO"<<'\n';
const ll N = 200005;
ll a[N], seg[N * 4], lazy[N * 4];

void buildSegTree(ll index, ll lo, ll hi){
    if(lo == hi){
        seg[index] = a[lo];
        return;
    }
    ll mid = (lo + hi) >> 1;
    buildSegTree(2 * index + 1, lo, mid);
    buildSegTree(2 * index + 2, mid + 1, hi);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

void rangeUpdate(ll index, ll lo, ll hi, ll l, ll r, ll val){
    if(lazy[index]){
        seg[index] += (hi - lo + 1) * lazy[index];
        if(lo != hi){
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(hi < l || lo > r) return;
    if(lo >= l && hi <= r){
        seg[index] += (hi - lo + 1) * val;
        if(lo != hi){
            lazy[2 * index + 1] += val;
            lazy[2 * index + 2] += val;
        }
        return;
    }
    ll mid = (lo + hi) >> 1;
    rangeUpdate(2 * index + 1, lo, mid, l, r, val);
    rangeUpdate(2 * index + 2, mid + 1, hi, l, r, val);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

ll rangeQuery(ll index, ll lo, ll hi, ll l, ll r){
    if(lazy[index]){
        seg[index] += (hi - lo + 1) * lazy[index];
        if(lo != hi){
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(lo >= l && hi <= r) return seg[index];
    if(hi < l || lo > r) return 0;
    ll mid = (lo + hi) >> 1;
    ll left = rangeQuery(2 * index + 1, lo, mid, l, r);
    ll right = rangeQuery(2 * index + 2, mid + 1, hi, l, r);
    return left + right;
}
void solve(ll tt){

}
int main(){
  optimize;
  //freopen("gcd.txt", "r", stdin);
  //freopen("lcm.txt", "w", stdout);
  ll T = 1;
  //cin >> T;
  for(ll i = 1; i <= T; i++){
    //cout << "Case " << i << ": ";
    solve(i);
  }
  return 0;
}

/**
 *  created:  30/04/2026 08:53:09
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
ll a[N], seg[N * 4];

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

void pointUpdate(ll index, ll lo, ll hi, ll node, ll val){
    if(lo == hi){
        seg[index] = val;
        return;
    }
    ll mid = (lo + hi) >> 1;
    if(node <= mid)
        pointUpdate(2 * index + 1, lo, mid, node, val);
    else
        pointUpdate(2 * index + 2, mid + 1, hi, node, val);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

ll pointUpdateQuery(ll index, ll lo, ll hi, ll l, ll r){
    if(lo >= l && hi <= r) return seg[index];
    if(hi < l || lo > r) return 0;
    ll mid = (lo + hi) >> 1;
    ll left = pointUpdateQuery(2 * index + 1, lo, mid, l, r);
    ll right = pointUpdateQuery(2 * index + 2, mid + 1, hi, l, r);
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

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define nl '\n'
// #define int long long
#define ll long long
#define flt long double
#define pb push_back
#define pf push_front
#define all(x) (x).begin(), (x).end() 
#define mp make_pair 
#define mpp map<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>

void solve() {
    int n, k; cin>>n>>k;
    if(n<=k) cout<<(n+k-1)/n<<nl;    
    else { // n>k
        // the value idea: to make k greater than n to get non-zero element by: "val" here below:
        ll d = (n+k-1)/k;
        ll val = d*k;

        cout<<(val+n-1)/n<<nl;
    }
}

signed main() {
    FAST_IO 
    int t; cin>>t; while(t--)
        solve();
   
    return 0;
}
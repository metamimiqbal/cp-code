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
#define dbg(x) cerr<<"#x "<<x<<endl;

ll optimalMerge(VEC fileSizes)
{
    priority_queue<ll, VEC, greater<ll>> Q;
    for(ll s : fileSizes)
        Q.push(s);
    ll totalCost = 0;
    // while(!Q.empty()) {
    //     cout<<Q.top()<<endl;
    //     Q.pop();
    // }

    while(Q.size() > 1)
    {
        ll a = Q.top();
        Q.pop();
        ll b = Q.top();
        Q.pop();
        ll merged = a + b;
        totalCost += merged;
        // dbg(endl);
        Q.push(merged);
    }
    return totalCost;
}

int main()
{
    VEC fileSizes = {20, 30, 10, 5};
    cout << "Minimum total merge cost = "
         << optimalMerge(fileSizes) << endl;
    return 0;
}
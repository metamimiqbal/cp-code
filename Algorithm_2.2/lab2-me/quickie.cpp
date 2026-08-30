#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>vec {2, 4, 3, 5, 1};

ll partition(ll l, ll r) {
    ll i = l-1;
    ll pvt = vec[r];
    for(ll j = l; j<r; j++) {
        if(vec[j]<=pvt) ++i, swap(vec[i], vec[j]);
    }
    swap(vec[i+1], vec[r]);
    return i+1;
}

void qs(ll l, ll r) {
    if(l >= r) return;

    ll p = partition(l, r);

    qs(l, p-1);
    qs(p+1, r);
}

int main() {
    qs(0, vec.size()-1);

    for(ll x : vec) cout<<x<<" ";
    cout<<endl;

    return 0;
}
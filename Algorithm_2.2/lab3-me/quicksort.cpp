#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>vec {10, 7, 8, 9, 1, 5};

ll partition(ll l, ll r) {
    ll pivot = vec[r];
    ll i = l-1;

    for(ll j = l; j < r; j++) {
        if(vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
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
    ll sz = vec.size();

    qs(0, sz-1);

    cout<<"Sorted array: ";
    for(ll x : vec) cout<<x<<" ";
    cout<<endl;

    return 0;
}
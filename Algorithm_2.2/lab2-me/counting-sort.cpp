#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>vec {5, 2, 8, 1, 4, 3, 2, 7, 5};

void cnt_sort() {
    ll mx = *max_element(vec.begin(), vec.end());

    vector<ll>cnt(mx+1, 0);

    for(ll x : vec)
        cnt[x]++;

    ll id = 0;

    for(ll i = 0; i <= mx; i++) {
        while(cnt[i]--) {
            vec[id++] = i;
        }
    }
}

int main() {
    cnt_sort();

    for(ll x : vec) cout<<x<<" ";
    cout<<endl;

    return 0;
}
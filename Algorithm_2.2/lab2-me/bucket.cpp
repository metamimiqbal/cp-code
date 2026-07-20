#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>vec {42, 32, 33, 52, 37, 47, 51};

void bucket_sort() {
    ll mx = *max_element(vec.begin(), vec.end());

    ll bucket = sqrt(vec.size())+1;

    vector<vector<ll>>b(bucket);

    for(ll x : vec) {
        ll id = x*bucket/(mx+1);
        b[id].push_back(x);
    }

    for(ll i = 0; i < bucket; i++)
        sort(b[i].begin(), b[i].end());

    vec.clear();

    for(ll i = 0; i < bucket; i++) {
        for(ll x : b[i])
            vec.push_back(x);
    }
}

int main() {
    bucket_sort();

    for(ll x : vec) cout<<x<<" ";
    cout<<endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>vec {170, 45, 75, 90, 802, 24, 2, 66};

void cnt_sort(ll pw) {
    vector<ll>cnt(10, 0);
    vector<ll>tmp(vec.size());

    for(ll x : vec)
        cnt[(x/pw)%10]++;

    for(ll i = 1; i < 10; i++)
        cnt[i] += cnt[i-1];

    for(ll i = vec.size()-1; i >= 0; i--) {
        ll d = (vec[i]/pw)%10;
        tmp[--cnt[d]] = vec[i];
    }

    vec = tmp;
}

void radix_sort() {
    ll mx = *max_element(vec.begin(), vec.end());

    for(ll pw = 1; mx/pw > 0; pw *= 10)
        cnt_sort(pw);
}

int main() {
    radix_sort();

    for(ll x : vec) cout<<x<<" ";
    cout<<endl;

    return 0;
}
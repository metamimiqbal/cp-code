#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vec {5, 4, 3, 2, 1};
void merge(ll l, ll md, ll r) {
    vector<ll>tmp;
    ll i = l, j = md+1;

    while(i <= md && j <= r) {
        if(vec[i] <= vec[j]) tmp.push_back(vec[i++]);
        else tmp.push_back(vec[j++]);
    }
    while(i <= md) tmp.push_back(vec[i++]);
    while(j <= r) tmp.push_back(vec[j++]);

    for(ll i = l; i <= r; i++) vec[i] = tmp[i-l];
}

void merge_sort(ll l, ll r) {
    if(l >= r) return;
    ll md = (l+r)/2;
    merge_sort(l, md);
    merge_sort(md+1, r);
    merge(l, md, r);
}

int main() {
    merge_sort(0, vec.size()-1);
    cout<<"Merge Sort:\n";
    for(ll x : vec) cout<<x<<" ";
    cout<<endl;
    return 0;
}
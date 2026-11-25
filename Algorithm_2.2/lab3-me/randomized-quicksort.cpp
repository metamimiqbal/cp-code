#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>vec {5, 9, 1, 7, 3, 8, 2, 6, 4};

ll partition(ll l, ll r) {
    ll pivot = vec[l];
    ll i = l-1, j = r+1;

    while(true) {
        do i++;
        while(vec[i] < pivot);

        do j--;
        while(vec[j] > pivot);

        if(i >= j) return j;

        swap(vec[i], vec[j]);
    }
}

void qs(ll l, ll r) {
    if(l >= r) return;

    ll k = l + rand()%(r-l+1);
    swap(vec[l], vec[k]);

    ll p = partition(l, r);

    qs(l, p);
    qs(p+1, r);
}

int main() {
    srand(time(0));

    qs(0, vec.size()-1);

    for(ll x : vec) cout<<x<<" ";
    cout<<endl;

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> vec {2, 4, 3, 5, 1};

pair<ll,ll> partition(ll l, ll r) {

    if(vec[l] > vec[r])
        swap(vec[l], vec[r]);

    ll p1 = vec[l];
    ll p2 = vec[r];

    ll i = l + 1;
    ll j = l + 1;
    ll k = r - 1;

    while(j <= k) {

        if(vec[j] < p1) {

            swap(vec[i], vec[j]);

            i++;
        }

        else if(vec[j] > p2) {

            while(vec[k] > p2 && j < k)
                k--;

            swap(vec[j], vec[k]);

            k--;

            if(vec[j] < p1) {

                swap(vec[i], vec[j]);

                i++;
            }
        }

        j++;
    }

    i--;
    k++;

    swap(vec[l], vec[i]);
    swap(vec[r], vec[k]);

    return {i, k};
}

void qs(ll l, ll r) {

    if(l >= r) return;

    pair<ll,ll> p = partition(l, r);

    qs(l, p.first - 1);

    qs(p.first + 1, p.second - 1);

    qs(p.second + 1, r);
}

int main() {

    qs(0, vec.size() - 1);

    for(ll x : vec)
        cout << x << " ";

    cout << endl;

    return 0;
}
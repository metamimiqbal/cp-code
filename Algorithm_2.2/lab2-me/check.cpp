#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> vec {170, 45, 75, 90, 802, 24, 2, 66};

void radix_sort() {
    ll mx = *max_element(vec.begin(), vec.end());

    for (ll dv = 1; mx / dv > 0; dv *= 10) {
        vector<ll> hash(10, 0);
        vector<ll> output(vec.size());

        // Count occurrences of the current digit
        for (ll x : vec) {
            hash[(x / dv) % 10]++;
        }

        // Convert counts into final positions
        for (int i = 1; i < 10; i++) {
            hash[i] += hash[i - 1];
        }

        // Traverse backwards to keep the sort stable
        for (int i = (int)vec.size() - 1; i >= 0; i--) {
            int digit = (vec[i] / dv) % 10;
            output[--hash[digit]] = vec[i];
        }

        vec = output;
        cout<<"vec:\n";
        for(auto x: vec) cout<<x<<" ";
        cout<<endl;
    }
}

int main() {
    radix_sort();

    for (ll x : vec) cout << x << " ";
    cout << endl;

    return 0;
}
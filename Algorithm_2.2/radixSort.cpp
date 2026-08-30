#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>vec {170, 45, 75, 90, 802, 24, 2, 66};

void radix_sort() {
    ll mx = *max_element(vec.begin(), vec.end());

    ll dv = 1;
    while(mx >= dv) {
        vector<ll>hash(10, 0);
        vector<ll>otpt(vec.size());
        for(int i =0; i<(int)vec.size(); i++) {
            hash[(vec[i]/dv)%10]++;
        }
        for(int i = 1; i<10; i++) 
        {
            hash[i] += hash[i-1];
        }
        
        for (int i = (int)vec.size() - 1; i >= 0; i--) {
            int dg = (vec[i]/dv)%10;
            otpt[hash[dg]-1] = vec[i];
            hash[dg]--;
        }
        vec = otpt;
        dv*=10;
    }
}

int main() {
    radix_sort();

    for(ll x : vec) cout<<x<<" ";
    cout<<endl;

    return 0;
}
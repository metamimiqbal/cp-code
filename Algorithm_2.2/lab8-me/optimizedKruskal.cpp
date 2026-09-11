#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define rrep(i, a, b) for(ll i = (a); i>=(b); --i)
#define each(x, a) for(auto &x: (a))
#define nl "\n"
#define spc " "

vector<ll>parent(1e6);
vector<ll>rank_value(1e6);

void makeSet(ll n) { // self looping each
    rep(i, 1, n+1) {
        parent[i] = i;
        rank_value[i] = 0;
    }
}

ll findSet(ll n) { // return root: which is ofc self loop.
    if(n == parent[n]) return n;
    parent[n] = findSet(parent[n]);
    return parent[n];
}

void unionSet(ll a, ll b) {
    ll x = findSet(a);
    ll y = findSet(b);
    if(x == y) return;
    if(rank_value[x] < rank_value[y]) parent[x] = y;
    else if(rank_value[x] > rank_value[y]) parent[y] = x;
    else { // rank_value[x] = rank_value[y]
        parent[y] = x;
        rank_value[x]++;
    }
}

bool sameSet(ll a, ll b) {
    return findSet(a) == findSet(b);
}

int main() {
    ll n; cin>>n;
    makeSet(n);
    
    ll numberOfUnions; cin>>numberOfUnions;
    rep(i, 0, numberOfUnions) {
        ll a, b; cin>>a>>b;
        unionSet(a, b);
    }
    
    ll a, b; cin>>a>>b;
    if(sameSet(a, b)) cout<<a<<" and "<<b<<" are in the same set\n";
    else cout<<a<<" and "<<b<<" are not in the same set\n";

    return 0;
}


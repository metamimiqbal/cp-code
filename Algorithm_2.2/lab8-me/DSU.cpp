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

class DisjointSet {
private:
    vector<ll> parent, rank_vec;

public:
    // Initialize N isolated elements (0 to N-1)
    DisjointSet(ll n) {
        parent.resize(n); 
        rank_vec.resize(n);
        parenting(n);
    }

    // Initialize parent and rank
    void parenting(ll n) {
        rep(i, 0, n) {
            parent[i] = i;
            rank_vec[i] = 1;
        }
    }

    // Find ultimate representative with Path Compression
    ll findRoot(ll x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }

    // Union by Rank
    bool uniting(ll x, ll y) {
        ll s1 = findRoot(x);
        ll s2 = findRoot(y);

        if(s1 == s2) return false;

        if(rank_vec[s1] == rank_vec[s2]) {
            parent[s1] = s2;
            rank_vec[s2]++;
        }
        else if(rank_vec[s1] > rank_vec[s2]) {
            parent[s2] = s1;
        }
        else {
            parent[s1] = s2;
        }

        return true;
    }

    // Check whether two elements belong to the same set
    bool sameSet(ll x, ll y) {
        return findRoot(x) == findRoot(y);
    }
};

int main() {
    ll n = 7;
    DisjointSet dsu(n);

    // Merge components
    dsu.uniting(0, 1);
    dsu.uniting(1, 2);
    dsu.uniting(3, 4);
    dsu.uniting(5, 6);

    // Merge two existing components
    dsu.uniting(2, 4);

    // Check connectivity
    cout << boolalpha;

    cout << "0 and 4: " << dsu.sameSet(0, 4) << nl;
    cout << "0 and 3: " << dsu.sameSet(0, 3) << nl;
    cout << "0 and 6: " << dsu.sameSet(0, 6) << nl;

    // Find representatives
    cout << "Root of 0: " << dsu.findRoot(0) << nl;
    cout << "Root of 3: " << dsu.findRoot(3) << nl;
    cout << "Root of 6: " << dsu.findRoot(6) << nl;

    return 0;
}
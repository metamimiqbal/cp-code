#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define THINK_LIKE_JACK_SPARROW FAST_IO

// datatype:
#define ll long long
#define flt long double
#define ull unsigned long long


// stl:
#define pll pair<ll, ll>
#define VEC vector<ll>
#define MAP map<ll, ll>
#define SET set<ll>
#define prque priority_queue<ll>
#define rprque priority_queue<ll, vector<ll>, greater<ll>> // reverse priority queue

// iteration:
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define rrep(i, a, b) for(ll i = (a); i>=(b); --i)
#define each(x, a) for(auto &x: (a))

// functions:
#define SUM(x) accumulate(all(x), 0LL)
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define string_toupper(s) transform(all(s), s.begin(), ::toupper)
#define string_tolower(s) transform(all(s), s.begin(), ::tolower)


// printing:
#define nl '\n'
#define spc " "
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define print(x) cout<<(x)<<'\n'

// debugging: 
#define dbg(x) cerr<<"[DEBUG] "<<#x<<" = "<<x<<nl
#define printv(v)                 \
    do {                          \
        for (auto &x : (v))       \
            cerr << x << ' ';     \
        cerr << '\n';             \
    } while (0)

// mathematical:
#define gcd __gcd
#define lcm(a, b) ((a)/gcd((a), (b))*(b))
#define modn(x) ((((x)%mod + mod))%mod)
#define ll_len(n) ((n) > 0 ? (int)floor(log10((long double)(n)) + 1) : 1) 
constexpr ll INF = 1e18;
constexpr ll MOD = 1000000007LL;
template<class T>
inline T sq(T x) { return x * x; }


// [ Why So Serious ]
void solve() {
    ll n, m; cin>>n>>m;
    string s; cin>>s;
    map<ll, ll>mp; 
    rep(i, 0, m) {
        ll x; cin>>x;
        mp[x]++;
    }

    vector<ll>p(n+1);
    p[0] = 1;

    rep(i, 1, n+1) {
        ll pos;
        if(i == 1) {
            pos = p[0];
            ++pos;
            if(s[i-1] == 'B') {
                while(mp.count(pos)) ++pos;
            }
            mp[pos]++; 
        } else {
            pos = p[i-2];
            if(s[i-2] == 'A') ++pos;
            else if(s[i-2] == 'B') {
                ++pos;
                while(mp.count(pos)) ++pos;
            }
            if(s[i-1] == 'A') ++pos;
            else if(s[i-1] == 'B') {
                ++pos;
                while(mp.count(pos)) ++pos;
            }
            mp[pos]++;
        }
        p[i] = pos;
    }
    cout<<mp.size()<<endl;
    for(auto [u, v]: mp) cout<<u<<spc;
    cout<<endl;
}

signed main() {
    THINK_LIKE_JACK_SPARROW
    int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
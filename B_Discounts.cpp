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
    ll n, k; cin>>n>>k;
    VEC v(n), d(k);
    for(auto &u: v) cin>>u;
    for(auto &u: d) cin>>u;
    
    sort(rall(v));
    VEC p(n+1);
    rep(i, 1, n+1) {
        p[i] = p[i-1] + v[i-1];
    }
    sort(all(d));
    ll r = 0;
    ll tk = 0;
    for(int i = 0; i<k; ++i) {
        ll l = r;
        r += d[i];
        // dbg(r), dbg(l);
        // dbg(p[r]), dbg(p[l]);
        if(r <= n) {
            tk += (p[r-1]-p[l]);
            // if(l == 0) tk += (p[r]-p[l]);
            // else tk += (p[r]-p[l]);
        } else {
            tk += (p[n]-p[l]);
            break;
            // dbg((p[n-1]-p[l]));
        }
        // dbg(tk);
    }

    // ++r;
    if(r < n) {
        rep(i, r, n) tk += v[i];
    }

    // for(auto u: p) cout<<u<<spc;
    // cout<<nl;


    cout<<tk<<nl;

}

signed main() {
    THINK_LIKE_JACK_SPARROW

    int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
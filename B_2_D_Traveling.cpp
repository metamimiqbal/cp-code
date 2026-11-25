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
    ll n, k, a, b; cin>>n>>k>>a>>b;
    vector<pair<ll, ll>>vpl;
    pair<ll, ll>aa, bb;
    rep(i, 0, n) {
        ll x, y; cin>>x>>y;
        vpl.push_back({x, y});
        if(i+1 == a) aa = make_pair(x, y);
        else if(i+1 == b) bb = make_pair(x, y);
    }


    ll mn1 = INF, mn2 = INF;
    rep(i, 0, k) {
        // a thek onno jekono ektate nambe, then oyta theke direct b
        if(a <= k) mn1 = 0;
        else mn1 = min(mn1, abs(vpl[i].first-aa.first) + abs(vpl[i].second-aa.second));
        if(b <= k) mn2 = 0;
        else mn2 = min(mn2, abs(vpl[i].first-bb.first) + abs(vpl[i].second-bb.second));
    }
    mn1 += mn2;

    ll dis = abs(aa.first-bb.first)+abs(aa.second-bb.second);

    cout<<min(mn1, dis)<<nl;
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
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
    ll n; cin>>n;
    VEC v(n);
    for(auto &u: v) cin>>u;
    ll keep = 0;
    rep(i, 0, n) {
        ll cn = 0;
        rep(j, 0, n) 
        {
            //to include duplicate took j = 0 from start.
            if(v[j] % v[i] == 0) ++cn;
        }
        keep = max(keep, cn);
    }
    cout<<n-keep<<nl;
    // MAP st;
    // rep(i, 0, n) {
    //     ll x; cin>>x;
    //     st[x]++;
    // }
    // VEC v;
    // for(auto [x, y]: st) {
    //     v.push_back(x);
    // }

    // // for(auto u: v) dbg(u);
    // ll nn = n;
    // n = st.size();
    // ll mxlen = 0;

    // ll value = v[0];
    // rep(i, 0, n-1) {
    //     // if(v[i+1] % v[i] == 0 and v[i+1]-v[i] >= v[i]) {
    //         // rep(j, i+1, n) {
    //             //     if(v[j]%v[i] == 0) {
    //                 //         ++cn;
    //                 //     }
    //                 // }
    //                 //     // dbg("bal");
    //                 // }
    //     ll d = -1;
    //     rep(j, i+1, n) {
    //         if(v[j] % v[i] == 0) {
    //             d = v[j] - v[i]; break;
    //         }
    //     }
        
    //     ll cn = 0;
    //     // if(d > 0 and v[i] <= d and d/v[i] == 1) {
    //     if(d > -1 and v[i] == d){
    //         rep(j, i+1, n) {
    //             if(v[j]%v[i] == 0) {
    //                 ++cn;
    //             }
    //         }
    //     }

    //     if(mxlen < cn) {
    //         value = v[i];
    //         mxlen = cn;
    //     }
    // }
    // // dbg(mxlen);

    // // dbg(mxlen);
    // // dbg(value);
    // ll keep = 0;
    // for(auto [u, vv]: st) {
    //     if(u % value == 0) {
    //         keep += vv;
    //     }
    // }
    // cout<<nn-keep<<nl;
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
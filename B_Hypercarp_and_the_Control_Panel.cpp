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
    rep(i, 0, n) cin>>v[i];
    if(n == 1) {
        cout<<1<<nl; return;
    }

    vector<pair<ll, ll>>b;
    rep(i, 0, n) {
        if(b.empty() || v[i] != v[i-1]) {
            b.push_back({v[i], 1});
        } else {
            b.back().second++;
        }
    }

    ll m = b.size();
    rep(i, 0, m-1) {
        if(b[i].second > 1 && b[i+1].second > 1) {
            cout<<m+2<<nl; return;
        }
    }

    rep(i, 0, m) {
        if(i < m-1 && b[i].second > 1 && (i+2 >= m || b[i+2].first != b[i].first)) {
            cout<<m+1<<nl; return;
        } 
        if(i > 0 && b[i].second > 1 && (i-2 < 0 || b[i-2].first != b[i].first)) {
            cout<<m+1<<nl; return;
        }
    }


    cout<<m<<nl; 
    return;

    // for(auto [x, y]: b) cout<<x<<spc<<y<<nl;


    // VEC pfx_freq(n);
    // pfx_freq[0] = 1;
    // rep(i, 1, n) {
    //     if(v[i]==v[i-1]) {
    //         pfx_freq[i] = pfx_freq[i-1] + 1;
    //     } else {
    //         pfx_freq[i] = 1;
    //     }
    // }

    // // for(auto u: pfx_freq) cout<<u<<spc;
    // // cout<<nl;
    // vector<pair<ll, ll>>vpr;
    // for(int i = 0; i<n-1; ) {
    //     while (i<n-1 && (v[i]==v[i+1])) ++i;
    //     if(v[i] != v[i+1]) {
    //         vpr.push_back({v[i], pfx_freq[i]});
    //         ++i;
    //     }
    // }

    // if(v[n-1] != v[n-2]) {
    //     vpr.push_back({v[n-1], 1});
    // }

    // for(auto [x, y]: vpr) cout<<x<<spc<<y<<nl;
    // ll ans = vpr.size();

    // // bool primary = false;
    // rep(i, 0, (ll)vpr.size()-1) {
    //     ll scnd = vpr[i].second;
    //     ll scnd1 = vpr[i+1].second;
    //     if(scnd > 1 && scnd1 > 1) {
    //         cout<<ans+2<<nl; return;
    //     }
    // }
    
    // // bool secondary = false;
    // // if(!primary) {
    //     rep(i, 0, (ll)vpr.size()-1) {
    //         ll scnd = vpr[i].second;
    //         ll scnd1 = vpr[i+1].second;
    //         if(scnd1 )
    //     }
    
    // cout<<ans<<nl; 

    // if(!primary && !secondary) {
    //     rep(i, 0, (ll)vpr.size()-1) {
    //         ll scnd = vpr[i].second;
    //         ll scnd1 = vpr[i+1].second;
    //         if(scnd > 0 && scnd1 > 0) {
    //             --scnd1, --scnd;
    //             vpr[i].second = scnd;
    //             vpr[i+1].second = scnd1;
    //             break;
    //         }
    //     }
    // } 


    // ll bad = 0;
    // for(auto [x, y]: vpr) {
    //     if(y > 0)
    //         bad += (y-1);
    // }
    // cout<<n-bad<<nl;

    // // for(auto [x, y]: vpr) {
    // //     cout<<x<<spc<<y<<nl;
    // // }
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
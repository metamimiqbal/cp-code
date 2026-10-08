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
    VEC a(n+1), b(n+1), c(n+1);
    rep(i, 1, n+1) cin>>a[i]>>b[i]>>c[i];

    vector<vector<ll>>dp(n+1, vector<ll>(4));
    
    rep(i, 1, n+1) {
        rep(j, 1, 4) { 
            if(j == 1) dp[i][j] = a[i];
            if(j == 2) dp[i][j] = b[i];
            if(j == 3) dp[i][j] = c[i];
        }
    }

    rep(i, 1, n+1) {
        rep(j, 1, 4) {
            if(j == 1) dp[i][j] = dp[i][j] + max(dp[i-1][j+1], dp[i-1][j+2]);
            else if(j==2) dp[i][j] = dp[i][j] + max(dp[i-1][j-1], dp[i-1][j+1]);
            else dp[i][j] = dp[i][j] + max(dp[i-1][j-1], dp[i-1][j-2]);
        }
    }
    ll ans = 0;
    rep(j, 1, 4) {
        ans = max(ans, dp[n][j]);
    }
    cout<<ans<<nl;
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    //int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
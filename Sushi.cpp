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



void solve() {
    ll n; cin>>n;
    ll c1 = 0, c2 = 0, c3 = 0;
    rep(i, 0, n) {
        ll x; cin>>x;
        if(x == 1) c1++;
        else if(x == 2) c2++;
        else c3++;
    }

    vector<vector<vector<double>>> dp(n+2, vector<vector<double>>(n+2, vector<double>(n+2, 0)));
    rep(c, 0, c3+1) {
        rep(b, 0, c2+c3+1) {
            rep(a, 0, n+1) {
                if(a+b+c == 0 || a+b+c > n) continue;
                double res = n;
                if(a > 0) res += a * dp[a-1][b][c];
                if(b > 0) res += b * dp[a+1][b-1][c];
                if(c > 0) res += c * dp[a][b+1][c-1];
                dp[a][b][c] = res / (a+b+c);
            }
        }
    }

    cout<<setprecision(12)<<dp[c1][c2][c3]<<nl;
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    solve();

    return 0;
}
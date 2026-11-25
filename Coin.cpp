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
    vector<string> g(n);
    each(s, g) cin>>s;

    VEC lo(n, 0), hi(n, 0), cnt(2*n+1, 0);
    rep(i, 0, n) {
        rep(j, 0, n) {
            ll c = g[i][j] == '@';
            if(i == 0 && j == 0) {
                lo[j] = 0;
                hi[j] = 0;
            }
            else if(i == 0) {
                lo[j] = lo[j-1] + c;
                hi[j] = hi[j-1] + c;
            }
            else if(j == 0) {
                lo[j] = lo[j] + c;
                hi[j] = hi[j] + c;
            }
            else {
                lo[j] = min(lo[j], lo[j-1]) + c;
                hi[j] = max(hi[j], hi[j-1]) + c;
            }
            cnt[lo[j]]++;
            cnt[hi[j]+1]--;
        }
    }

    rep(x, 0, 2*n-1) {
        if(x > 0) cnt[x] += cnt[x-1];
        cout<<cnt[x]<<nl;
    }
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    solve();

    return 0;
}
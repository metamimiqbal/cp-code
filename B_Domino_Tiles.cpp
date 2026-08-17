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

bool checkNull(string s) {
    ll n = s.size();
    rep(i, 0, n-2) {
        string x = s.substr(i, 3);
        if(x == "0?0" || x == "000" || x == "010" || x == "1?1" || x == "101" || x=="111") {
            return 1;
        }
    }
    return 0;
}

// [ Why So Serious ]
void solve() {
    ll n; string s;
    cin>>n>>s;

    bool qstn = false;
    rep(i, 0, n) {
        if(s[i] == '?') qstn = true;
    }

    if(checkNull(s)){
        cout<<0<<nl; return;
    } else if(!qstn) {
        cout<<1<<nl; return;
    }

    ll ans = 0;
    if(s.substr(0, 2) == "??" && s.substr(n-2, 2) == "??") ans += 4;
    else if((s[0] == '?') || (s[1] == '?')) ans += 2;

    cout<<ans<<nl;
    
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
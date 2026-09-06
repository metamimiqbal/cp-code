//Job Sequencing with Deadlines
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

// bool cmp(tuple<ll, ll, ll>tpl1, tuple<ll, ll, ll>tpl2) {
//     if((get<0>(tpl1)) == (get<0>(tpl2))) return (get<1>(tpl1)) > (get<1>(tpl2));
//     return (get<1>(tpl1)) > (get<1>(tpl2));
// }

// [ Why So Serious ]
void solve() {
    ll n; cin>>n;
    vector<tuple<ll, ll, ll>>vtpl;
    ll mxDeadline = -1;
    rep(i, 0, n) {
        ll id, ddln, mrk;
        cin >> id >> ddln >> mrk;
        mxDeadline = max(mxDeadline, ddln);
        vtpl.push_back({mrk, ddln, id});
    }
    sort(rall(vtpl));

    VEC slot(mxDeadline+1);
    ll mark = 0;
    for(int i = 0; i<n; i++) {
        ll dedline = get<1>(vtpl[i]);
        while(slot[dedline] != 0 and dedline > 0) dedline--;
        if(dedline > 0) {
            mark += get<0>(vtpl[i]);
            slot[dedline] = get<2>(vtpl[i]);
        }
    }
    for(int i = 1; i<=mxDeadline; i++) {
        if(slot[i] != 0) cout<<slot[i]<<spc;
    }

    cout<<nl<<mark<<nl;
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    // int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}

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
    VEC a(n), b(m);
    rep(i, 0, n) cin>>a[i];
    rep(i, 0, m) cin>>b[i];

    sort(all(a));
    sort(all(b));
    int i, j, k;

    if (n<2*m) {
        no;
        return;
    }
    for(i = n-1, j = n-2, k = m-1; i >= 0 && j>=0 && k>=0 ; ) {
        if(a[i] < b[k]) {
            no; return;
        }
        while(a[j] > b[k] && j > 0) --j;
        if(i >=0 && j>= 0 && (a[j] <= b[k])) --i, --k, --j;
        else {
            no; return;
        }
    }

    if(k == -1) {
        yes;
    }
    else {
        no;
    }

    // if(m > n) {
    //     no; return;
    // } else if(m == n) {
    //     if(a != b) {
    //         no; return;
    //     }
    // }

    // if(a[0] > b[0]) {
    //     no; return;
    // }

    // ll kybar = 0;
    // rep(i, 0, m) {
    //     auto itr = lower_bound(all(a), b[i]);
    //     if(itr == a.end()) {
    //         no; return;
    //     } else {
    //         ll idx = itr - a.begin();
    //         if(a[idx] != b[i]) ++kybar;
    //     }
    // }

    // n -= kybar;
    // if(m <= n) {
    //     yes;
    // } else {
    //     no;
    // }



    // ll mx1 = *max_element(all(a));
    // ll mx2 = *max_element(all(b));

    // if(mx1 >= mx2) 

    // vector<ll>pos(n, 0);
    // rep(i, 0, m) {
    //     // auto itr = lower_bound()
    //     ll l = i, r = n-1;
    //     while(pos[l] == 1) ++l;
    //     while(pos[r] == 1) --r;
    //     // bool paycire = false;
    //     ll min_idx = -1;
    //     while(l<=r) {
    //         ll md = l + (r-l)/2;
    //         if(a[md] >= b[i] && pos[md] == 0) {
    //             min_idx = min(min_idx, md);
    //             r = md - 1;
    //         } else {
    //             l = md + 1;
    //         }
    //     }
    //     if(min_idx != -1) {
    //         // while(a[i] <= b[i] && pos[i] == 1) 
    //         if(a[i] <= b[i] && a[min_idx] >= b[i]) pos[min_idx] = 1, pos[i] = 1;
    //         else {
    //             no; return;
    //         }
            
    //     } else {
    //         no; return;
    //     }
    // }
    // yes;
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
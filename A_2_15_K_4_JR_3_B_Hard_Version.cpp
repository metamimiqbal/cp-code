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
    ll d1 = 0, d2 = 0;
    rep(i, 0, n) cin>>v[i];
    sort(rall(v));
    rep(i, 0, n) {
        if(d1 <= d2) {
            d1 += (1<<v[i]);
        } else {
            d2 += (1<<v[i]);
        }
    }

    cout<<d1*d2<<nl;



    // ll sunno = 0;
    // VEC v;
    // rep(i, 0, n) {
    //     ll x; cin>>x;
    //     if(x==0) sunno++;
    //     else v.push_back(x);
    // }
    
    // if(sunno == n) {
    //     if(n&1) {
    //         cout<<n-1<<nl;
    //     } else {
    //         cout<<(n*n)/4<<nl;
    //     }
    //     return;
    // }
    
    
    // // if(n==2 and sunno == n) {
    // //     cout<<1<<nl; return;
    // // }


    // ll d1 = 0, d2=0;
    // if(sunno&1) {
    //     d1++, sunno--;
    // }
    // d2 += sunno;
    // // if(sunno == 2 and d1 == 0) 
    // // else if(d1 == 0) d1 += sunno/2, d2 += sunno/2;
    // // else d2 += sunno;

    // // if(!v.empty()) {
    // if(d1==0) d1 += (1<<v[0]);
    // else d2 += (1<<v[0]);
    
    // rep(i, 1, (ll)v.size()) {
    //     d2 += (1<<v[i]);
    // }
    // // }
    
    // // dbg(d1);
    // // dbg(d2);
    // cout<<d1*d2<<nl;
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
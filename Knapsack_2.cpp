// 

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


ll knapsack0_1(vector<ll>&val, vector<ll>&wt, vector<vector<ll>>&mem, ll V, ll n) {
    if(V == 0) return 0;
    if(n == 0) return INF;
    if(mem[n][V] != -1) return mem[n][V];
    ll take = INF;
    if(V >= val[n]) {
        take = wt[n] + knapsack0_1(val, wt, mem, V - val[n], n-1);
    }
    ll notTaken = knapsack0_1(val, wt, mem, V, n-1);

    return mem[n][V] = min(take, notTaken);
}


// [ Why So Serious ]
void solve() {
    ll n, W; cin>>n>>W;
    vector<ll>wt(n+1), v(n+1);
    rep(i, 1, n+1) {
        cin>>wt[i]>>v[i];
    }

    ll sumV = SUM(v);
    vector<vector<ll>>mem(n+1, vector<ll>(sumV+1, -1));
    // for(auto x: mem) {
    //     for(auto y: x) cout<<y<<spc;
    //     cout<<nl;
    // }

    rrep(i, sumV, 0) {
        if(knapsack0_1(v, wt, mem, i, n) <= W) {
            cout<<i<<nl; break;
        }
    }


    // if(n==1) {
    //     if(wt[1] <= W) {
    //         cout<<v[1]<<nl; return;
    //     }
    // }

    // rep(i, 1, n+1) {
    //     ll taken = 0;
    //     if(wt[i] <= W) {
    //         taken = v[i] + dp[i-1][W-wt[i]];
    //         W -= wt[i];
    //     }
    //     ll notTaken = dp.back();
    // }

}

signed main() {
    THINK_LIKE_JACK_SPARROW

    // int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
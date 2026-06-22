#include <bits/stdc++.h>
using namespace std;

// [printing follow up] 
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define Think_Like_Jack_Sparrow FAST_IO

// [ datatype ] 
#define ll      long long
#define ull     unsigned long long
#define flt     long double
#define pll     pair<ll, ll>
#define pii     pair<int, int>

// [ stl ]
#define VEC     vector<ll>
#define VPR     vector<pair<ll, ll>>
#define VVEC    vector<vector<ll>>
#define MAP      map<ll, ll>
#define SET     set<ll>
#define prque   priority_queue<ll>
#define gprque  priority_queue<ll, vector<ll>, greater<ll>>

// [ container ops ]
#define pb(x)       push_back(x)
#define eb(x)       emplace_back(x)
#define pf(x)       push_front(x)
#define popb(x)     (x).pop_back()
#define popf(x)     (x).pop_front()
#define mkpr(a,b)    make_pair(a, b)
#define mktpl(a,b,c)   make_tuple(a, b, c)

//  [ iterating ]
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define sz(x)       (ll)(x).size()
#define rep(i,a,b)  for(ll i=(a);i<(b);++i)
#define rrep(i,a,b) for(ll i=(a);i>=(b);--i)
#define each(x,a)   for(auto &x : a)

// [ sorting ]
#define srt(x)      sort(all(x))
#define rsrt(x)     sort(rall(x))
#define rev(x)      reverse(all(x))
#define uniq(x)     (x).erase(unique(all(x)), (x).end())

// [ Function ] 
#define SUM(x)          accumulate(all(x), 0LL)
#define MAX(x)          *max_element(all(x))
#define MIN(x)          *min_element(all(x))
#define STR_TOUPPER(s)  transform(all(s), s.begin(), ::toupper)
#define STR_TOLOWER(s)  transform(all(s), s.begin(), ::tolower)
#define sq(x)           ((x)*(x))
#define gcd             __gcd
#define lcm(a,b)        ((a)/gcd(a,b)*(b))
#define mod             1000000007
#define modn(x)         (((x)%mod+mod)%mod)
#define ll_len(n)       ((n) > 0 ? (int)floor(log10((long double)(n)) + 1) : 1)

// [ Printing ]
#define yes             cout << "YES\n"
#define no              cout << "NO\n"
#define pyes            cout << "Yes\n"
#define pno             cout << "No\n"
#define print(x)        cout << (x) << nl
#define nl              '\n'
#define spc             " "

// [ Dropping Anchor ] 
#define dbg(x)          cerr << "[DBG] " << #x << " = " << x << nl
#define printv(v)       for(auto x : v) cerr << x << ' '; cerr << nl

// [ numbering ]
const ll inf  =  1e18;
const ll M    =  1e7;
// vector<int> dp(M, -1);
// bitset<M> vc;

// [ Graph/Grid ]
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
// 8-directional:
// const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
// const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

// [ Why so serious? ] 
void solve() {
    ll a, b, x; cin>>a>>b>>x;
    // ll aa = max(a, b);
    // ll bb = min(a, b);
    // ll val1 = aa - bb;
    // ll val2 = abs(bb - (aa%x)) + aa/x;
    // ll val3 = abs(aa - (bb%x)) + bb/x;
    // ll val4 = abs((aa % x) - (bb % x)) + aa/x + bb/x;

    // cout<<min(min(val1, val4), min(val2, val3))<<nl;
    // dbg(val1);
    // dbg(val2);
    // dbg(val3);
    
    // cout<<min(min(abs(bb - (aa%x)) + 1, abs(aa - (bb%x))+1), min(aa - bb, abs(aa%x - bb%x) + 2))<<nl;

    // if(val2 < 0 && val3 < 0) {
    //     cout<<val1<<nl;
    // } else if(val2 < 0) {
    //     cout<<min(val1, val3)<<nl;
    // } else if(val3 < 0) {
    //     cout<<min(val1, val2)<<nl;
    // } else {
    //     cout<<min(min(val1, val2), val3)<<nl;
    // }
    ll ans = inf;
    ll vag = 0;
    while(a != b) {
        if(a<b) swap(a, b);
        ans = min(ans, (a-b) + vag);
        a = a/x;
        ++vag;
        // dbg(a), dbg(vag), dbg(ans);
    } 
    ans = min(ans, vag);

    if(ans == inf) {
        cout<<0<<nl;
    } else {
        cout<<ans<<nl;
    }
}

// [ Black Pearl ] 
signed main() {
    Think_Like_Jack_Sparrow

    int t; cin >> t; while(t--)
    solve();

    return 0;
}
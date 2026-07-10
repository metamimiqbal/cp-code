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
    ll t, h, u; cin>>t>>h>>u;
    ll ans = 3*(t+h+u);
    ll tu = min(t, u);
    ans -= 2*tu;
    t -= tu, u -= tu;
    if(t > 0 and h > 0){
        ll th = min(t, 2*h);
        ans -= th;
        t -= th, h -= th;
    }
    if(t > 0) {
        ans -= t/2;
    }

    cout<<ans<<nl;

    // if(t > 0 and h > 0 and u > 0) {
    //     ll mn = min(t, min(h, u));
    //     ans += mn * 7;
    //     t -= mn;
    //     h -= mn;
    //     u -= mn;
    // }
    
    // if(t == 0 and h>0 and u>0) {
    //     //h, u
    //     ans += (h+u)*3;
    //     ll mn = min(h, u);
    //     h -= mn;
    //     u -= mn;
    // } else if(h == 0 and t>0 and u>0) {
    //     // t, u
    //     ans += min(t, u) * 4;
    //     ans += (max(t, u)-min(t, u)) * 3;
    //     ll mn = min(t, u);
    //     t -= mn;
    //     u -= mn;
    // } else if(u == 0 and h>0 and t>0) {
    //     // t, h
    //     ans += min(t, h) * 5;
    //     ans += (max(t, h)-min(t, h)) * 3;
    //     ll mn = min(t, h);
    //     t -= mn;
    //     h -= mn;
    //     // dbg(ans);
    //     // dbg(t), dbg(h);
    // }

    // if(t == 0 and h == 0 and u>0) {
    //     ans += (u*3);
        
    // } else if(t == 0 and u == 0 and h>0) {
    //     ans += (h*3);
    //     // dbg(ans);
    // } else if(h == 0 and u == 0 and t>0) {
    //     ans += (t/2 * 5);
    //     if(t&1) {
    //         ans += 3;
    //     }
    // } 
    // cout<<ans<<nl;
}

// [ Black Pearl ] 
signed main() {
    Think_Like_Jack_Sparrow

    int t; cin >> t; while(t--)
    solve();

    return 0;
}
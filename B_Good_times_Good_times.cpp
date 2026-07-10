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
ll len(string s) {
    set<char>sc;
    for(auto u: s) sc.insert(u);
    return sc.size();
}

void solve() {
    ll x; cin>>x;
    // rep(i, 2, 101) {
    //     if(len(to_string(x*i)) <= 2) {
    //         cout<<x*i<<nl; return;
    //     }
    // } 
    // cout<<"Paini\n";
    // ll ln = ceil(log10(x)) - 1;
    // ll i = 1;
    // rep(k, 0, ln) i*=10;
    // if(i == 1) ++i;

    // // dbg(i);dbg(ln);
    // rep(k, i, x+1) {
    //     if(len(to_string(x*k))<=2) {
    //         cout<<x*k<<nl; return;
    //     }
    //     dbg("hoccena");
    // }
    // // dbg("paini");
    ll ln = ceil(log10(x));
    ll ans = 1;
    rep(k, 0, ln) ans *= 10;
    ++ans;
    // ans = ans * x;
    cout<<ans<<nl;
}

// [ Black Pearl ] 
signed main() {
    Think_Like_Jack_Sparrow

    int t; cin >> t; while(t--)
    solve();

    return 0;
}
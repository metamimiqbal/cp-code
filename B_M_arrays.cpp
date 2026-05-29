/**
 * Assalamualaikum
 * Bismillah
 * "The problem is not the problem. The problem is the attitude about the problem."
 *
 * My people: the whole muslim ummah from uyghoor to rohingya, from the people of Falastin to Sudan; 
 * I belong to them and I dream of UMA (United Muslim Aliance) with them - Be Iznillah
 * 
 * -------------------------------------------------------------
 *  |      Following up the legacy (Sorif Osman Bin Hady)      |
 * -------------------------------------------------------------
 */
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

// [ The Great Adventure ] 
void solve() {
    ll n, m; cin>>n>>m;
    ll arr[n];
    MAP mp;
    for(auto &i: arr) {
        cin>>i;
        mp[i % m]++;
        // dbg(i);
        // dbg(i%m);
    }

    // rep(i, 0, n) cout<<arr[i]<<spc;
    // cout<<nl;
 
    ll grped = 0;
    ll isolated = 0;
    bool sunnoRemainder = false;
    ll ekebare_isolated = 0;

    // dbg("MAP");
    // for(auto [u, v]: mp) cout<<u<<spc<<v<<nl;
    // dbg("End of Map");

    for(auto [u, v]: mp) {
        if(u % m == 0) {
            sunnoRemainder = true;
            continue;
        }
        // dbg("Within Map: "), dbg(u);
        if(mp.count(m-u)) {
            ll mx = max(mp[m-u], v);
            ll mn = min(mp[m-u], v);
            ++grped;
            if(mx != mn) isolated += (mx - mn - 1);
            // dbg(isolated);
            // dbg(grped);
            // dbg(u), dbg(m-u);
        } else {
            ekebare_isolated += v;
            // cout<<"Ekebare Isolated: "<<u<<v<<" ta\n";
        }
    }
    // dbg("MAP");
    // for(auto [u, v]: mp) cout<<u<<spc<<v<<nl;

    
    grped = (grped + 1)/2;
    isolated /= 2;

    // dbg(ekebare_isolated);
    // dbg(isolated);
    // dbg(grped);
    // dbg(sunnoRemainder);

    ll val = grped + isolated + ekebare_isolated;
    ll ans = (sunnoRemainder) ? val+1 : val;

    // dbg(ans);
    cout<<ans<<nl;
}

// [ Black Pearl ] 
signed main() {
    Think_Like_Jack_Sparrow

    int t; cin >> t; while(t--)
    solve();

    return 0;
}
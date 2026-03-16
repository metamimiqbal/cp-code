/**
 * Bismillah
 * "The problem is not the problem. The problem is your attitude about the problem."
 *
 * THE BLACK PEARL CODEBASE
 * -------------------------------------------------------------
 * |  "Take what you can, give nothing back!"                  |
 * -------------------------------------------------------------
 */

#include <bits/stdc++.h>
using namespace std;

// [Navigating the Seas] 
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define Think_Like_Jack_Sparrow FAST_IO

// [ The Pirate's Gold ] 
#define ll      long long
#define ull     unsigned long long
#define flt     long double

// [ Provisions & Cargo ]
#define VEC     vector<ll>
#define VPR     vector<pair<ll,ll>>
#define VVEC    vector<vector<ll>>
#define MP      map<ll, ll>
#define SET     set<ll>
#define que     queue<ll>
#define dque    deque<ll>
#define prque   priority_queue<ll>
#define aprque  priority_queue<ll, vector<ll>, greater<ll>>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)   (ll)(x).size()

// [ Combat Maneuvers ] --------------------------------------
#define SUM(x)          accumulate(all(x), 0LL)
#define MAX(x)          *max_element(all(x))
#define MIN(x)          *min_element(all(x))
#define STR_TOUPPER(s)  transform(all(s), s.begin(), ::toupper)
#define STR_TOLOWER(s)  transform(all(s), s.begin(), ::tolower)
#define gcd             __gcd
#define lcm(a,b)        ((a)/gcd(a,b)*(b))
#define mod             1000000007
#define modn(x)         (((x)%mod+mod)%mod)
#define ll_len(n)       ((n) > 0 ? (int)floor(log10((long double)(n)) + 1) : 1)

// [ Constant Voyages ] 
#define rep(i,a,b)      for(ll i=(a);i<(b);++i)
#define rrep(i,a,b)     for(ll i=(a);i>=(b);--i)
#define each(x,a)       for(auto &x : a)

// [ Parlay ]
#define yes             cout<<"YES\n"
#define no              cout<<"NO\n"
#define nl              '\n'
#define spc             " "

// [ Dropping Anchor ] 
#define dbg(x)          cerr << "[DBG] " << #x << " = " << x << nl
#define printv(v)       for(auto x : v) cerr << x << ' '; cerr << nl

// [ Secret Map ] 
const ll M = 1e7;
// vector<int> dp(octroi, -1);
// bitset<octroi> vc;

// [ The Great Adventure ] ----------------------------------
// void solve() {
//     ll n, x, y; cin>>n>>x>>y;
//     if(x != 0) ++x;

//     VEC v(n), mid, bahir;
//     ll lowest_min_val_idx = 0;
//     ll mn = LLONG_MAX;
//     rep(i, 0, n) {
//         cin>>v[i];
//         if(i >= x && i < y) {
//             mid.push_back(v[i]);
//             mn = min(mn, v[i]);
//         } else {
//             bahir.push_back(v[i]);
//         }
//     }

//     auto mid_mn_idx = lower_bound(all(mid), mn) - mid.begin();

//     VEC remid;
//     rep(i, mid_mn_idx, mid.size()) remid.push_back(mid[i]);
//     rep(i, 0, mid_mn_idx) remid.push_back(mid[i]);

//     ll small_idx = -1;
//     rep(i, 0, bahir.size()) {
//         if(bahir[i] <= mn) {
//             small_idx = i;
//         } else break;
//     }
//     if(small_idx == -1) {
//         rep(i, 0, remid.size()) cout<<remid[i]<<spc;
//         rep(i, 0, bahir.size()) cout<<bahir[i]<<spc;
//         cout<<nl;
//     } else {
//         rep(i, 0, small_idx+1) cout<<bahir[i]<<spc;
//         rep(i, 0, remid.size()) cout<<remid[i]<<spc;
//         rep(i, small_idx+1, bahir.size()) cout<<bahir[i]<<spc;
//         cout<<nl;
//     }
// }
// void solve() {
//     ll n, x, y; cin>>n>>x>>y;
//     if(x != 0) ++x;

//     VEC v(n), mid, bahir;
//     ll lowest_min_val_idx = 0;
//     ll mn = LLONG_MAX;
//     rep(i, 0, n) {
//         cin>>v[i];
//         if(i >= x && i <= y) {
//             if(mn > v[i]) {
//                 mn = v[i];
//                 lowest_min_val_idx = i;
//             }
//         } else {
//             bahir.push_back(v[i]);
//         }
//     }

//     rep(i, lowest_min_val_idx, y+1) {
//         mid.push_back(v[i]);
//     }
//     rep(i, x, lowest_min_val_idx) mid.push_back(v[i]);

//     ll mini = v[lowest_min_val_idx];
//     VEC ans;
    
//     ll kddur = 0;
//     rep(i, 0, bahir.size()) {
//         if(bahir[i] <= mini) ans.push_back(v[i]);
//         else break;
//         kddur++;
//     }

//     rep(i, 0, mid.size()) ans.push_back(mid[i]);

//     rep(i, kddur+1, bahir.size()) ans.push_back(bahir[i]);

//     rep(i, 0, n) cout<<ans[i]<<spc; 
//     cout<<nl;
// }


void solve() {
    ll n, x, y; 
    cin >> n >> x >> y;

    VEC outside, middle;
    // The portals are at x and y. 
    // Elements from index 0 to x-1 are outside.
    // Elements from index x to y-1 are inside.
    // Elements from index y to n-1 are outside.
    rep(i, 0, n) {
        ll val; cin >> val;
        if (i >= x && i < y) {
            middle.push_back(val);
        } else {
            outside.push_back(val);
        }
    }

    if (middle.empty()) {
        each(v, outside) cout << v << spc;
        cout << nl;
        return;
    }

    // 1. Find the smallest element in the middle and rotate it to the front
    auto min_it = min_element(all(middle));
    rotate(middle.begin(), min_it, middle.end());

    ll middle_min = middle[0];

    // 2. Find where to insert the middle segment into the outside segment
    // We want the first element in 'outside' that is LARGER than our 'middle_min'
    auto insert_pos = outside.end();
    rep(i, 0, sz(outside)) {
        if (outside[i] > middle_min) {
            insert_pos = outside.begin() + i;
            break;
        }
    }

    // 3. Perform the insertion
    outside.insert(insert_pos, all(middle));

    // 4. Output
    rep(i, 0, n) {
        cout << outside[i] << (i == n - 1 ? "" : " ");
    }
    cout << nl;
}

// [ Black Pearl ] -------------------------------------------
signed main() {
    Think_Like_Jack_Sparrow

    int t; cin >> t; while(t--)
    solve();

    return 0;
}

// -------------------------------------------------------------
// You'll always be remembered, mate (Sorif Osman Bin Hady)
// -------------------------------------------------------------
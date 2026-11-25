// #include<bits/stdc++.h>
// using namespace std;

// #define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
// #define THINK_LIKE_JACK_SPARROW FAST_IO

// // datatype:
// #define ll long long
// #define flt long double
// #define ull unsigned long long


// // stl:
// #define pll pair<ll, ll>
// #define VEC vector<ll>
// #define MAP map<ll, ll>
// #define SET set<ll>
// #define prque priority_queue<ll>
// #define rprque priority_queue<ll, vector<ll>, greater<ll>> // reverse priority queue

// // iteration:
// #define all(x)  (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sz(x) (ll)(x).size()
// #define rep(i, a, b) for(ll i = (a); i<(b); ++i)
// #define rrep(i, a, b) for(ll i = (a); i>=(b); --i)
// #define each(x, a) for(auto &x: (a))

// // functions:
// #define SUM(x) accumulate(all(x), 0LL)
// #define MAX(x) *max_element(all(x))
// #define MIN(x) *min_element(all(x))
// #define string_toupper(s) transform(all(s), s.begin(), ::toupper)
// #define string_tolower(s) transform(all(s), s.begin(), ::tolower)


// // printing:
// #define nl '\n'
// #define spc " "
// #define yes cout<<"YES\n"
// #define no cout<<"NO\n"
// #define print(x) cout<<(x)<<'\n'

// // debugging: 
// #define dbg(x) cerr<<"[DEBUG] "<<#x<<" = "<<x<<nl
// #define printv(v)                 \
//     do {                          \
//         for (auto &x : (v))       \
//             cerr << x << ' ';     \
//         cerr << '\n';             \
//     } while (0)

// // mathematical:
// #define gcd __gcd
// #define lcm(a, b) ((a)/gcd((a), (b))*(b))
// #define modn(x) ((((x)%mod + mod))%mod)
// #define ll_len(n) ((n) > 0 ? (int)floor(log10((long double)(n)) + 1) : 1) 
// constexpr ll INF = 1e18;
// constexpr ll MOD = 1000000007LL;
// template<class T>
// inline T sq(T x) { return x * x; }


// // [ Why So Serious ]
// void solve() {
//     ll x, y, m; cin>>x>>y>>m;
//     string s; cin>>s;

//     rep(i, 0, m) {
//         if(s[i] == '+') {
//             if(y > 0) ++y;
//             else {
//                 if(x>0) {
//                     x--, y++;
//                 } else {
//                     x++;
//                 }
//             }
//         } else {
//             if(y > 0) {
//                 y--, x++;
//             } else {
//                 if(x > 0) {
//                     x--;
//                 } else {
//                     cout<<1<<nl; return;
//                 }
//             }
//         }
//     }
//     // cout<<x<<spc<<y<<nl;
//     cout<<x+y<<nl;
// }

// signed main() {
//     THINK_LIKE_JACK_SPARROW

//     int tt; cin>>tt; while(tt--)
//     solve();

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, m;
    cin >> x >> y >> m;

    string s;
    cin >> s;

    const int NEG = -1000000000;
    int N = x + y + m;

    vector<int> dp(N + 1, NEG);
    dp[y] = x;

    int ans = x + y;

    for (char c : s) {
        vector<int> ndp(N + 1, NEG);

        for (int j = 0; j <= N; j++) {
            if (dp[j] < 0) continue;

            int ones = dp[j];

            if (c == '+') {
                // Copy a power-2 stone
                if (j > 0 && j < N) {
                    ndp[j + 1] = max(
                        ndp[j + 1], ones
                    );
                }

                // Upgrade a power-1 stone
                if (ones > 0 && j < N) {
                    ndp[j + 1] = max(
                        ndp[j + 1], ones - 1
                    );
                }
            }
            else {
                // Remove a power-1 stone
                if (ones > 0) {
                    ndp[j] = max(
                        ndp[j], ones - 1
                    );
                }

                // Downgrade a power-2 stone
                if (j > 0) {
                    ndp[j - 1] = max(
                        ndp[j - 1], ones + 1
                    );
                }
            }
        }

        // Zero stones: no further moves possible.
        if (ndp[0] == 0) {
            ndp[0] = NEG;
        }

        dp.swap(ndp);

        for (int j = 0; j <= N; j++) {
            if (dp[j] >= 0) {
                ans = max(ans, dp[j] + j);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}



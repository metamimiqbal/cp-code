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
//     ll n; cin>>n;
//     string a, b; cin>>a>>b;

//     rep(i, 0, n) {
//         if(a[i] == '1') {
//             bool issueSolve = false;
//             ll j = i-1;
//             if(j >= 0) {
//                 if(b[j] == '0') {
//                     issueSolve = true;
//                     b[j] = '1';
//                     a[i] = '0';
//                     continue;
//                 }
//                 while(j-2 >= 0 && b[j-2] == '1') {
//                     j-=2;
//                 }
//                 if(j-2>=0 && b[j-2] == '0') {
//                     issueSolve = true;
//                     b[j-2] = '1';
//                     a[i] = '0';
//                 }
//             }

//             if(!issueSolve) {
//                 j = i+1;
//                 if(j < n) {
//                     if(b[j] == '0') {
//                         issueSolve = true;
//                         b[j] = '1';
//                         a[i] = '0';
//                         continue;
//                     }

//                     while(j+2 < n && b[j+2] == '1') j+=2;
//                     if(j+2 < n && b[j+2] == '0') {
//                         issueSolve = true;
//                         b[j+2] = '1';
//                         a[i] = '0';
//                     }
//                 }
//             }
//             if(!issueSolve) {
//                 no; return;
//             }
//         }
//     }
//     yes;
// }

// signed main() {
//     THINK_LIKE_JACK_SPARROW

//     int tt; cin>>tt; while(tt--)
//     solve();

//     return 0;
// }

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
    string a, b; cin>>a>>b;

    ll a_evn = 0, a_od = 0, b_evn = 0, b_od = 0;

    rep(i, 0, n) {
        if(i&1) {
            a_od += a[i] == '1';
            b_od += b[i] == '0';
        } else {
            a_evn += a[i] == '1';
            b_evn += b[i] == '0';
        }
    }

    if(a_od <= b_evn && a_evn <= b_od) yes;
    else no;
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    int tt; cin>>tt; while(tt--)
    solve();

    return 0;
}
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
        VEC v(n), Sign(n);
        ll i =0;
        for(auto &u: v) {
            cin>>u;
            Sign[i++] = (u>1) ? 1: -1;
        }
        ll ans = 0;
        for(int i = 0; i<n-2; ) {
            ll val = Sign[i]+Sign[i+1]+Sign[i+2];
            if(!val) ans = max() 
        } 
        
        // ll onlyevenPos = 0, onlyevenNeg = 0, onlyoddOdd = 0, onlyoddEven = 0, even = 0, odd = 0;
        ll evnNeg = 0, evnPos = 0, oddNeg = 0, oddPos = 0;
        ll mxevn = 0, mxodd = 0;
        // rep(i, 0, n) {
        //     cin>>v[i];
        //     if(i%2 == 0) {
        //         if(v[i]>1) evnPos++;
        //         else evnNeg++;
        //         mxevn = max(v[i], mxevn);
        //     } else {
        //         if(v[i]>1) oddPos++;
        //         else oddNeg++;
        //         mxodd = max(v[i], mxodd);
        //     }
        // }
        // if((evnPos == 0) || (oddPos == 0) || (evnNeg == 0) || (oddNeg == 0)) cout<<mxevn+mxodd<<nl;
        // else cout<<accumulate(all(v), 0ll)<<nl;

    }

    signed main() {
        THINK_LIKE_JACK_SPARROW

        int tt; cin>>tt; while(tt--)
        solve();

        return 0;
    }
#include <bits/stdc++.h>

using namespace std;

class CP {
public:
    // ==================== DATATYPE ====================
    using ll = long long;
    using flt = long double;
    using ull = unsigned long long;

    // ==================== STL ====================
    using pll = pair<ll, ll>;
    using VEC = vector<ll>;
    using MAP = map<ll, ll>;
    using SET = set<ll>;
    using maxque = priority_queue<ll>;
    using minque = priority_queue<ll, vector<ll>, greater<ll>>;

    // ==================== CONSTANTS ====================
    static constexpr ll INF = 1e18;
    static constexpr ll MOD = 1000000007LL;


    // ==================== ITERATION ====================
    template <class T>
    static auto all(T& x) {
        return pair(x.begin(), x.end());
    }

    template <class T>
    static auto rall(T& x) {
        return pair(x.rbegin(), x.rend());
    }
    template <class T>
    static ll sz(const T& x) {
        return (ll)x.size();
    }


    // ==================== FUNCTIONS ====================
    template <class T>
    static T sq(T x) {
        return x * x;
    }

    template <class T>
    static T SUM(const T& x) {
        return accumulate(x.begin(), x.end(), T{});
    }
    template <class T>
    static auto MAX(const T& x) {
        return *max_element(x.begin(), x.end());
    }

    template <class T>
    static auto MIN(const T& x) {
        return *min_element(x.begin(), x.end());
    }


    // ==================== MATHEMATICAL ====================
    static ll gcd(ll a, ll b) {
        return __gcd(a, b);
    }
    static ll lcm(ll a, ll b) {
        return (a / gcd(a, b)) * b;
    }
    static ll modn(ll x) {
        return ((x % MOD) + MOD) % MOD;
    }
    static int ll_len(ll n) {
        if (n == 0)
            return 1;

        n = abs(n);

        int len = 0;

        while (n) {
            ++len;
            n /= 10;
        }

        return len;
    }


    // ==================== PRINTING ====================

    static constexpr char nl = '\n';
    static constexpr const char* spc = " ";

    static void yes() {
        cout << "YES\n";
    }

    static void no() {
        cout << "NO\n";
    }

    template <class T>
    static void print(const T& x) {
        cout << x << '\n';
    }


    // ==================== DEBUGGING ====================

    template <class T>
    static void dbg(const char* name, const T& x) {
        cerr << "[DEBUG] " << name << " = " << x << nl;
    }

    template <class T>
    static void printv(const T& v) {
        for (const auto& x : v)
            cerr << x << ' ';

        cerr << nl;
    }


    // ==================== STRING ====================

    static void string_toupper(string& s) {
        transform(
            s.begin(),
            s.end(),
            s.begin(),
            [](unsigned char c) {
                return toupper(c);
            }
        );
    }

    static void string_tolower(string& s) {
        transform(
            s.begin(),
            s.end(),
            s.begin(),
            [](unsigned char c) {
                return tolower(c);
            }
        );
    }


    // ==================== IO ====================

    static void fast_io() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};


// ========================================================
// SOLUTION
// ========================================================

void solve() {
    ll n; cin>>n;
    VEC v(n);
    for(auto &u: v) cin>>u;

}


// ========================================================
// MAIN
// ========================================================

signed main() {

    CP::fast_io();

    // int tt;
    // cin >> tt;
    // while (tt--)
    //     solve();

    solve();

    return 0;
}
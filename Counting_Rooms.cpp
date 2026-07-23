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

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


// void dfs(vector<vector<char>>graph, char start, set<char>&visited) {
//     visited.insert(start);
//     for(auto neighbor: graph[start]) {
//         if(!visited.count(neighbor)) dfs(graph, start, visited);
//     }
// }

ll nn, mm;
void dfs(ll r, ll c, vector<vector<bool>>&visited, vector<vector<char>> &graph) {
    visited[r][c] = true;
    rep(i, 0, 4) {
        ll nr = r + dr[i];
        ll nc = c + dc[i];
        if(nr < 0 || nr >= nn || nc < 0 || nc >= mm || visited[nr][nc] || graph[nr][nc] == '#') continue;
        dfs(nr, nc, visited, graph);
    }
}


// [ Why So Serious ]
void solve() {
    ll r, c;
    cin>>r>>c;
    nn = r, mm = c;
    vector<vector<char>> graph(r, vector<char>(c));

    rep(i, 0, r) {
        rep(j, 0, c) {
            cin>>graph[i][j];
        }
    }

    vector<vector<bool>>visited(r, vector<bool>(c, false));
    ll room = 0;
    rep(i, 0, r) {
        rep(j, 0, c) {
            if(graph[i][j] == '.' && !visited[i][j]) {
                ++room;
                dfs(i, j, visited, graph);
            }
        }
    }
    cout<<room<<nl;
    
    // set<char>visited;
    // rep(i, 0, r) {
    //     rep(j, 0, c) {
    //         rep(k, 0, 4) {
    //             rep(l, 0, 4){
    //                 char nr = graph[i][j] + dr[k];
    //                 char nc = graph[i][j] + dc[k];
    //                 if(nr <= 0 || nc <= 0 || nr == '#' || nc == '#' || visited.count(graph[n]))
    //             }
    //     }
    
    // }
    //         } 
    
    
}

signed main() {
    THINK_LIKE_JACK_SPARROW

    // int t; cin>>t; while(t--)
    solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
 
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (auto& x : arr) {
        cin >> x;
    }
    if (is_sorted(all(arr))) {
        cout << "YES" << "\n";
        return;
    }
    if (a > b) {
        swap(a, b);
    }
    int e = gcd(a, b);
    for (int i = 0; i < e; i++) {
        for (int j = i; j < n; j += e) {
            if ((arr[j] - (i + 1)) % e != 0) {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
    return;
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int tc = 1;
    cin >> tc;
    for (int i = 0; i < tc; i += 1) {
        solve();
    }
    return 0;
}
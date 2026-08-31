#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define flt long double
#define VEC vector<ll>
#define all(x)  (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define rrep(i, a, b) for(ll i = (a); i>=(b); --i)
#define each(x, a) for(auto &x: (a))

void jobSequence(VEC &j, VEC &p, VEC &d) {
    ll n = sz(j);
    vector<tuple<ll,ll,ll>> jobs;
    rep(i, 0, n) {
        jobs.push_back({j[i], p[i], d[i]});
    }
    sort(all(jobs), [](auto &a, auto &b) {
        return get<1>(a) > get<1>(b); // using custom comparator
    });

    for(auto [u, v, w]: jobs) {
        cout<<"job: "<<u<<" profit: "<<v<<" deadline: "<<w<<endl;
    }

    ll D = 0;
    each(job, jobs) {
        D = max(D, get<2>(job));
    }

    D = min(n, D);
    VEC slot(D+1, -1);
    ll totalProfit = 0;
    each(job, jobs) { // Schedule each job
        ll jobID = get<0>(job);
        ll profit = get<1>(job);
        ll deadline = get<2>(job);
        ll lastPossible = min(D, deadline);
        rrep(t, lastPossible, 1) {
            if(slot[t] == -1) {
                slot[t] = jobID;
                totalProfit += profit;
                break;
            }
        }
    }

    cout<<"job Sequence: ";
    rep(i, 1, D + 1) {
        if(slot[i] != -1)
            cout << slot[i] << " ";
    }
    cout<<endl<<"Total Profit: "<<totalProfit<<"\n";
}


int main() {
    VEC j{1, 2, 3}, p{1, 3, 2}, d {2, 3, 1};
    // ll n; cin>>n;
    // VEC j(n), p(n), d(n);
    // for(auto &in: j) cin >> in;
    // for(auto &in: p) cin >> in;
    // for(auto &in: d) cin >> in;
    jobSequence(j, p, d);
}
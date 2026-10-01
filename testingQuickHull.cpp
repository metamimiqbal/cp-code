#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define flt long double
#define VEC vector<ll>
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define rrep(i, a, b) for(ll i = (a); i>=(b); --i)
#define each(x, a) for(auto &x: (a))

struct Point{ll x, y;};
vector<Point>hull;

ll cross(Point A, Point B, Point C) {
    return (B.x-A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}

vector<Point>



int main() {
    ll n; cin>>n;
    vector<Point>pts(n);
    for(auto &p: pts) cin>>p.x>>p.y;

}


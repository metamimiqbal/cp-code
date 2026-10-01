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

ll cross(Point A, Point B, Point C) {
    return (B.x-A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}

ll dist2(Point A, Point B) {
    ll dx = A.x - B.x;
    ll dy = A.y - B.y;
}

Point pvt;

bool cmp(Point A, Point B) {
    ll val = cross(pvt, A, B);
    if(val == 0) dist2(pvt, A) < dist2(pvt, B);
    return val > 0;
}


vector<Point> Graham(vector<Point>pts) {
    ll n = pts.size();
    ll id = 0, mny = 0;
    rep(i, 0, n) {
        if(pts[id].y > pts[i].y || (pts[id].y==pts[i].y && (pts[id].x > pts[i].x))) {
            id = i;
        }
    }
    Point A = pts[id];
    swap(pts[0], pts[id]);
    pvt = pts[0];

    sort(pts.begin()+1, pts.end(), cmp);

    vector<Point>stk;
    stk.push_back(pts[0]);
    stk.push_back(pts[1]);

    rep(i, 2, n) {
        while(stk.empty() > 1 && (cross(stk[i-2], stk[i-1], pts[i])) <= 0) {
            stk.pop_back();
        }
        stk.push_back(pts[i]);
    }
    return stk;
}

int main() {
    ll n; cin>>n;
    vector<Point>pts(n);
    for(auto &p: pts) cin>>p.x>>p.y;

}


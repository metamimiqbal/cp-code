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
    return ((B.x - A.x)*(C.y - A.y) - (B.y-A.y)*(C.x-A.x));
}


void findHull(vector<Point>pts, Point A, Point B) {
    ll maxDist = 0, id = -1;;
    rep(i, 0, (ll)pts.size()) {
        ll d = cross(A, B, pts[i]);
        if(d > maxDist) {
            maxDist = d;
            id = i;
        }
    }

    if(id == -1) {
        hull.push_back(B); return;
    }

    Point C = pts[id];
    vector<Point>leftAC, leftCB;
    for(auto p: pts) {
        if(cross(A, C, p) > 0) leftAC.push_back(p);
        if(cross(C, B, p) > 0) leftCB.push_back(p);
    }
    findHull(leftAC, A, C);
    findHull(leftCB, C, B);;
}


vector<Point> quickHull(vector<Point>pts) {
    hull.clear();
    if(pts.size() < 3) {
        return pts;
    }

    ll minI = 0, maxI = 0;
    rep(i, 0, (ll)pts.size()) {
        if(pts[minI].x > pts[i].x) minI = i;
        if(pts[maxI].x < pts[i].x) maxI = i;
    }

    Point A = pts[minI], B = pts[maxI];

    vector<Point> upper, lower;
    for(auto p: pts) {
        ll d = cross(A, B, p);
        if(d > 0) upper.push_back(p);
        else if(d < 0) lower.push_back(p);
    }

    hull.push_back(A);
    findHull(upper, A, B);
    // hull.push_back(B);
    findHull(lower, B, A);
    return hull;
}   


int main() {
    vector<Point> p {
        {0, 0},
        {5, 0},
        {3, 4},
        {-3, -4}
    };
    vector<Point>ans = quickHull(p);
    ans.pop_back();
    for(auto a: ans) {
        cout<<a.x<<" "<<a.y<<endl;
    }
}


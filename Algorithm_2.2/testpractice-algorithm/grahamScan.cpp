#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point { ll x, y; };

Point pivot;

ll cross(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

ll dist2(Point A, Point B) {
    ll dx = A.x - B.x, dy = A.y - B.y;
    return dx * dx + dy * dy;
}

bool polarCompare(Point A, Point B) {
    ll d = cross(pivot, A, B);
    if (d == 0) return dist2(pivot, A) < dist2(pivot, B);
    return d > 0;
}

vector<Point> grahamScan(vector<Point> pts) {
    int n = pts.size();
    if (n < 3) return pts;

    int lowest = 0;
    for (int i = 1; i < n; i++) {
        if (pts[i].y < pts[lowest].y ||
           (pts[i].y == pts[lowest].y && pts[i].x < pts[lowest].x))
            lowest = i;
    }
    swap(pts[0], pts[lowest]);
    pivot = pts[0];

    sort(pts.begin() + 1, pts.end(), polarCompare);

    vector<Point> stk;
    stk.push_back(pts[0]);
    stk.push_back(pts[1]);

    for (int i = 2; i < n; i++) {
        while (stk.size() > 1 &&
               cross(stk[stk.size()-2], stk[stk.size()-1], pts[i]) <= 0)
            stk.pop_back();
        stk.push_back(pts[i]);
    }

    return stk;
}

int main() {
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (auto& p : pts) cin >> p.x >> p.y;

    vector<Point> h = grahamScan(pts);
    for (auto& p : h) printf("%lld %lld\n", p.x, p.y);

}
#include <bits/stdc++.h>
using namespace std;

pair <int,int> pivot;

bool comp(pair<int,int> p1, pair<int,int> p2) {
    float angle1 = atan2(p1.second - pivot.second, p1.first - pivot.first);
    float angle2 = atan2(p2.second - pivot.second, p2.first - pivot.first);

    if (angle1 == angle2) {
        int d1 = (p1.first - pivot.first) * (p1.first - pivot.first) +
                 (p1.second - pivot.second) * (p1.second - pivot.second);
        int d2 = (p2.first - pivot.first) * (p2.first - pivot.first) +
                 (p2.second - pivot.second) * (p2.second - pivot.second);
        return d1 < d2;
    }
    return angle1 < angle2;
}

int findSide(pair<int,int> p1, pair<int,int> p2, pair<int,int> p) {
    int val = (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);
    if (val > 0) return 1;
    else if (val < 0) return -1;
    else return 0;
}

void graham_scan(vector <pair<int,int>> v) {
    pivot = {INT_MAX, INT_MAX};
    int min = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        min = (v[i].second < min) ? v[i].second : min;
    }
    int index = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == min) {
            if (v[i].first < pivot.first) {
                pivot = v[i]; index = i;
            }
        }
    }
    v.erase(v.begin()+index);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin(),v.end(),comp);
    stack <pair<int,int>> s;
    s.push(pivot);
    s.push(v[0]);
    v.erase(v.begin());
    for (auto &i : v) {
        while (s.size() > 1) {
            pair<int,int> top = s.top(); s.pop();
            pair<int,int> top2 = s.top();
            s.push(top);
            if (findSide(top2, top, i) > 0) break;
            s.pop();
        }
        s.push(i);
    }
    cout << endl << "The Convex Hull Points: " << endl;
    while (!s.empty()) {
        cout << "(" << s.top().first << ", " << s.top().second << ")" << " ";
        s.pop();
    }
}



int main() {
    vector <pair<int,int>> v;
    cout << "How many points: ";
    int n; cin >> n;
    pair <int,int> p;
    for (int i = 0; i < n; i++) {
        p = make_pair(rand() % 10, rand() % 10);
        v.push_back(p);
    }
    cout << endl << "Generated Points: ";
    for (int i = 0; i < n; i++) {
        cout << "(" << v[i].first << ", " << v[i].second << ")" << " ";
    }
    graham_scan(v);
}
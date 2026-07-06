#include <bits/stdc++.h>
using namespace std;

int findSide(pair<int,int> p1, pair<int,int> p2, pair<int,int> p) {
    int val = (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);
    if (val > 0) return 1;
    else if (val < 0) return -1;
    else return 0;
}

pair <int,int> farthest(vector<pair<int,int>> set, pair<int,int> p1, pair<int,int> p2) {
    int d = 0;
    pair<int,int> p;
    for (auto i : set) {
        int dis = abs((p2.first-p1.first)*(p1.second-i.first)-(p1.first-i.first)*(p2.second-p1.second)) / sqrt((p2.first-p1.first)*(p2.first-p1.first)+(p2.second-p1.second)*(p2.second-p1.second));
        if (dis > d) {
            d = dis; p = i;
        }
    } return p;
} // can return an empty point!

bool comp(pair<int,int> a, pair<int,int> b) {
    if (a.second > b.second) return true;
    else return false;
}

void quickhull(vector<pair<int,int>> set) {
    if (set.size() < 3) {
        cout << "Hull not possible with less than 3 points." << endl;
        return;
    }
    sort(set.begin(),set.end());
    pair<int,int> p1 = set[0];
    sort(set.begin(),set.end(),comp);
    pair<int,int> p2 = set[1];
}

int main() {
    vector<pair<int,int>> set = { {0,0}, {0,10}, {5,5}, {5,-5}, {2,2}, {2,-2} };

}
#include <bits/stdc++.h>
using namespace std;

int v = 4;
int e = 5;

void Bellman_Ford(vector<pair<int,int>> edge, vector<int> weight) {
    vector<int> d(v, 10000);
    d[0] = 0;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int v1 = edge[j].first;
            int v2 = edge[j].second;

            if (d[v1] + weight[j] < d[v2]) {
                d[v2] = d[v1] + weight[j];
            }
        }
    }

    for (int i = 0; i < d.size(); i++) {
        cout << i << " " << d[i] << endl;
    }
}

int main() {
    vector<pair<int,int>> edge(e);
    vector<int> weight(e);
    edge = {
        {0,1},
        {0,3},
        {1,0},
        {1,2},
        {2,0},
        {2,3},
        {3,0}
    };
    weight = {3,7,8,2,5,1,2};

    Bellman_Ford(edge, weight);
}
#include <bits/stdc++.h>
using namespace std;
// tuple: weight, node, node

void prim (vector<vector<int>> graph) {
    set<int> v;
    using edge = tuple<int,int,int>;
    priority_queue <edge, vector<edge>, greater<edge>> p;
    vector<edge> mst;

    v.insert(0); // root
    int i = 0;
    while (v.size() < graph.size()) {
        for (int j = 0; j < graph.size(); j++) {
            if (graph[i][j] != 0 && i != j) { // 0 means no edge and i = j means self edge
                p.push({graph[i][j],i,j});
                graph[i][j] = graph[j][i] = 0;
            }
        }

        label:
        int next_vertex = get<2>(p.top());
        if (v.count(next_vertex)) {
            p.pop();
            goto label;
        }
        mst.push_back(p.top()); p.pop();
        v.insert(next_vertex);
        i = next_vertex;
    }

    sort(mst.begin(), mst.end());
    cout << endl << "The MST: " << endl;
    for (auto i : mst) {
        cout << get<1>(i) << " - " << get<2>(i) << ", " << get<0>(i) << endl;
    }
}

int main() {
    cout << "Number of Vertices: ";
    int n; cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i].push_back(0);
        }
    }

    cout << "How many Edges: "; cin >> n;
    cout << "Enter the Edges and Weights (Like: 1 2 11): " << endl;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
    }

    prim(graph);
}
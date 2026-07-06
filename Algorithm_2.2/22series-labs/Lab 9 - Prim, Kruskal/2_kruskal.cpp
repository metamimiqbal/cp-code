#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find (int n) {
    if (parent[n] == n) return n;
    return find(parent[n]);
}

void merge (int n1, int n2) {
    int root = parent[n1];
    int change = parent[n2];
    for (int i = 0; i < parent.size(); i++) {
        if (parent[i] == change) parent[i] = root;
    }
}

void kruskal (vector<vector<int>> graph) {

    for (int i = 0; i < graph.size(); i++) { // every node's parent is itself
        parent.push_back(i);
    }

    using edge = tuple<int,int,int>;
    vector <edge> e; // all edges
    vector <edge> mst; // safe edges

    for (int i = 0; i < graph.size(); i++) { // every edge now in e
        for (int j = i; j < graph.size(); j++) {
            if (graph[i][j] != 0 && i != j) { // 0 means no edge and i = j means self edge
                e.push_back({graph[i][j],i,j});
            }
        }
    }

    sort(e.begin(), e.end()); // sorted according to weight in increasing order

    set<int> v;
    edge i = e[0];
    while (v.size() < graph.size()) {
        int n1, n2;
        n1 = get<1>(i);
        n2 = get<2>(i);
        if (find(n1) != find(n2)) {
            mst.push_back(i);
            merge(n1,n2);
        }
        v.insert(n1);
        v.insert(n2);
        e.erase(e.begin());
        i = e[0];
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

    kruskal(graph);
}
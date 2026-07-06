#include <bits/stdc++.h>
using namespace std;
// tuple: weight, node, node

void dijkstra (vector<vector<int>> graph) {
    set<int> mark;
    vector<int> d(graph.size(), INT_MAX);

    // root = 0
    d[0] = 0;
    int selected = 0;
    while(mark.size() < graph.size()) {
        int m = INT_MAX;
        for (int i = 0; i < d.size(); i++) { // i = vertex
            if (mark.find(i) == mark.end()) { // i is not selected yet
                if (d[i] < m) { 
                    m = d[i];
                    selected = i;
                }
            }
        };
        mark.insert(selected);

        for (int i = 0; i < graph[selected].size(); i++) { // considering the edges with the selected vertex
            if (graph[selected][i] > 0 && d[selected] + graph[selected][i] < d[i]) {
                d[i] = d[selected] + graph[selected][i];
            }
        }
    }

    for (auto i : d) cout << i << " ";
}

int main() {
    cout << "Number of Vertices: ";
    int n; cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i].push_back(0);
        }
    }

    cout << "How many Edges: "; cin >> n;
    cout << "Enter the Edges and Weights (Like: 1 2 11): " << endl;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
    }

    dijkstra(graph);
}
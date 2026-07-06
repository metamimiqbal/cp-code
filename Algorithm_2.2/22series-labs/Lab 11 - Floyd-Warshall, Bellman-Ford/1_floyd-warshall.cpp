#include <bits/stdc++.h>
using namespace std;

void Floyd_Warshall(vector<vector<int>> graph) {
    for (int k = 0; k < graph.size(); k++) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                if (graph[i][j] > (graph[i][k] + graph[k][j])) {
                    graph[i][j] = (graph[i][k] + graph[k][j]);
                }
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    vector<vector<int>> graph(n, vector<int> (n));
    graph = {
        {0,3,10000,7},
        {8,0,2,10000},
        {5,10000,0,1},
        {2,10000,10000,0},
    };

    Floyd_Warshall(graph);
}
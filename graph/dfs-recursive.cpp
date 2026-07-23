#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> graph = {
    {'A', {'B', 'C'}},
    {'B', {'G', 'A'}},
    {'C', {'A', 'G', 'F'}},
    {'D', {'E'}},
    {'E', {'D', 'F'}},
    {'F', {'C', 'G', 'E'}},
    {'G', {'B', 'F', 'C'}}
};

void DFS(unordered_map<char, vector<char>> &graph,
         char vertex,
         unordered_set<char> &visited)
{
    visited.insert(vertex);
    cout << vertex << " ";

    for (char neighbor : graph[vertex])
    {
        if (visited.find(neighbor) == visited.end())
        {
            DFS(graph, neighbor, visited);
        }
    }
}

int main()
{
    unordered_set<char> visited;

    DFS(graph, 'A', visited);
    cout<<endl;
    return 0;
}
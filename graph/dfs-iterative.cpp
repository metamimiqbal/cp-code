#include <bits/stdc++.h>
using namespace std;


void dfs_iterative(map<char, vector<char>>graph, char start) {
    set<char>visited;
    stack<char>stk;
    
    stk.push(start);
    while(!stk.empty()) {
        char node = stk.top();
        stk.pop();
        if(!visited.count(node)) {
            visited.insert(node);
            cout<<node<<" ";
            for(char neighbor: graph[node]) stk.push(neighbor);
        }
    }
}


void dfs_recursive(map<char, vector<char>>graph, char start, set<char>&visited) {
    visited.insert(start);
    cout<<start<<" ";
    for(auto neighbor: graph[start]) {
        if(!visited.count(neighbor)) {
            dfs_recursive(graph, neighbor, visited);
        }
    }
}


int main()
{
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'G', 'A'}},
        {'C', {'A', 'G', 'F'}},
        {'D', {'E'}},
        {'E', {'D', 'F'}},
        {'F', {'C', 'G', 'E'}},
        {'G', {'B', 'F', 'C'}}
    };

    dfs_iterative(graph, 'A');
    cout<<endl;
    set<char>st;
    dfs_recursive(graph, 'A', st);
    cout<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


int main() {
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'G', 'A'}},
        {'C', {'A', 'G', 'F'}},
        {'D', {'E'}},
        {'E', {'D', 'F'}},
        {'F', {'C', 'G', 'E'}},
        {'G', {'B', 'F', 'C'}}
    };
    
    for(auto [u, v]: graph) {
        for(auto x: v) {
            cout<<x<<" ";
        }
        cout<<endl;
    } 

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

void spanningTree(){
    cout<<"Input: \n";
    int V,E;
    cin>>V>>E;
    vector<vector<int>> edges(E,vector<int>(3));
    for(int i = 0; i<E; i++)
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];

    vector<vector<pair<int,int>>> adj(V+1);
    for(auto edge: edges){
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<bool> visited(V+1);
    int mnCost=0;
    while(!pq.empty()){
        pair<int,int> p=pq.top();
        int wt=p.first;
        int v=p.second;
        pq.pop();

        if(!visited[v]){
            mnCost+=wt;
            visited[v]=true;
            for(auto [x,y]: adj[v])
                pq.push({y,x});
        }
    }
    cout<<"Output: \n";
    cout<<mnCost<<'\n';
}

signed main(){
    spanningTree();
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

void dijkstra(){
    int V,E,src;
    cout<<"Input: \n";
    cin>>V>>E;
    vector<vector<int>> edges(E,vector<int>(3));
    for(int i = 0; i<E; i++)
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    cin>>src;

    vector<vector<pair<int,int>>> adj(V);

    for(auto edge : edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(V,INT_MAX);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();

        if(d>dist[u]) continue;

        for(auto [v,w] : adj[u]){
            if(d+w<dist[v]){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }

    cout<<"Output: \n";
    for(int i = 0; i<V; i++)
        cout<<dist[i]<<" ";
    cout<<'\n';
}

signed main(){
    dijkstra();
    return 0;
}
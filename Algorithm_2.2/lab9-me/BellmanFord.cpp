#include<bits/stdc++.h>

using namespace std;

void bellmanFord(){
    int V,E,src;
    cout<<"Input: \n";
    cin>>V>>E;
    vector<vector<int>> edges(E,vector<int>(3));
    for(int i = 0; i<E; i++)
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    cin>>src;

    vector<int> dist(V,1e9);
    dist[src]=0;

    for(int i = 1; i<=V-1; i++){
        for(auto edge : edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(dist[u]!=1e9&&dist[u]+w<dist[v])
                dist[v]=dist[u]+w;
        }
    }

    for(auto edge : edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        if(dist[u]!=1e9&&dist[u]+w<dist[v]){
            cout<<"Output: \n";
            cout<<-1<<'\n';
            return;
        }
    }

    cout<<"Output: \n";
    for(int i = 0; i<V; i++)
        cout<<dist[i]<<" ";
    cout<<'\n';
}

signed main(){
    bellmanFord();
    return 0;
}
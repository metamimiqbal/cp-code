#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX / 4; // "infinity". Divided by 4 so dist[u]+w can never overflow.

int main() {
    int n,m;
    cin>>n>>m; // n = number of nodes, m = number of edges

    // adj[u] = list of {neighbor, weight}
    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        // input is 1-indexed (nodes 1..n), but our vector is 0-indexed (0..n-1)
        // so shift both endpoints down by 1
        --u;--v;
        // undirected graph: add the edge in both directions
        // (for a directed graph, only the first push_back)
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int s;
    cin>>s; // source node, also given 1-indexed
    // --s for the same reason as --u, --v above:
    // the user types 1..n, but dist[] and adj[] use 0..n-1.
    // Without this, s=n would go out of bounds and s=1 would start from the wrong node.
    --s;

    // dist[i] = best known distance from s to i. Starts as INF (not reached yet)
    vector<ll> dist(n,INF);

    // min-heap of {distance, node}. Smallest distance is always on top.
    // priority_queue is a max-heap by default, so greater<> flips it to min-heap.
    priority_queue<pair<ll,int>,
                   vector<pair<ll,int>>,
                   greater<pair<ll,int>>> pq;

    dist[s]=0;       // distance from source to itself is 0
    pq.push({0,s});  // start the search from the source

    while(!pq.empty()){
        // take the node with the smallest distance among everything in the heap
        auto [d,u]=pq.top();
        pq.pop();

        // STALE ENTRY CHECK.
        // We never delete old entries from the heap. When we find a shorter path
        // to a node, we just push a new {smaller dist, node} entry. The old
        // {bigger dist, node} entry is still sitting in the heap.
        // d = the distance this entry was pushed with.
        // dist[u] = the best distance we know for u right now.
        // If d != dist[u], then d is outdated (dist[u] got improved after this
        // entry was pushed), and u was already processed with the better value.
        // So skip it. Without this line the code is still correct, just slower.
        if(d!=dist[u])continue;

        // go through every neighbor of u
        // order = just the order edges were added to adj[u] (input order).
        // It does NOT matter for correctness, because we try to relax ALL
        // neighbors anyway. The order that actually matters in Dijkstra is
        // which NODE we pick next, and that is decided by the heap (smallest dist first).
        for(auto [v,w]:adj[u]){
            // relaxation: is going s -> ... -> u -> v shorter than the best known path to v?
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v}); // push the improved distance; the old entry for v becomes stale
            }
        }
    }

    // print answers. INF means v is not reachable from s
    for(int i=0;i<n;i++){
        if(dist[i]==INF)cout<<"INF ";
        else cout<<dist[i]<<" ";
    }
    cout<<"\n";
}
class Solution {
  static 
  
  
  
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        parent.resize(V);
        rank.resize(V);
        sort(edges.begin(), edges.end(), cmp);
        
        parenting(V);
        
        int cst = 0, cn = 0;
        for(auto edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            
            if(findRoot(u) != findRoot(v)) {
                uniting(u, v);
                cst += w;
                cn++;
                if(cn == V-1) {
                    break;
                }
            }
        }
        return cst;
    }
};
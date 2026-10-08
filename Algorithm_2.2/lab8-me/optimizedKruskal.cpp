#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define rrep(i, a, b) for(ll i = (a); i>=(b); --i)
#define each(x, a) for(auto &x: (a))
#define nl "\n"
#define spc " "

bool cmp(vector<int>&a, vector<int>&b) {
      return a[2] < b[2];
  }
  
  vector<int>parent, rank_vec;
  void parenting(int n) {
      for(int i=0; i<n; i++) {
          parent[i] = i;
          rank_vec[i] = 1;
      }
  }
  
  int findRoot(int x) {
      if(parent[x] == x) return x;
      return parent[x] = findRoot(parent[x]);
  }
  
  void uniting(int x, int y) {
      int s1 = findRoot(x), s2 = findRoot(y);
      
      if(rank_vec[s1] == rank_vec[s2]) parent[s1] = s2, rank_vec[s1]++;
      else if(rank_vec[s1] > rank_vec[s2]) parent[s2] = s1;
      else if(rank_vec[s2] > rank_vec[s1]) parent[s1] = s2;
  }

int kruskalsMST(int V, vector<vector<int>> &edges) {
    parent.resize(V);
    rank_vec.resize(V);
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



int main() {
    
    return 0;
}


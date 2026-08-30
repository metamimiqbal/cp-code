class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        
        int nr = mat.size();
        int nc = mat[0].size();
        int time = 0;
        queue<pair<pair<int, int>, int>>que;
        int fresh = 0;
        for(int i = 0; i<nr; i++) {
            for(int j = 0; j<nc; j++) {
                if(mat[i][j] == 2) que.push({{i, j}, 0});
                else if(mat[i][j] == 1) ++fresh;
            }
        }
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        vector<vector<int>>vis(nr, vector<int>(nc));
        int cnFresh = 0;
        while(!que.empty()) {
            int r = que.front().first.first;
            int c = que.front().first.second;
            int tt = que.front().second;
            time = max(time, tt);
            que.pop();
            if(mat[r][c] == 1) ++cnFresh;
            for(int i = 0; i<4; i++) {
                int rr = r + drow[i];
                int cc = c + dcol[i];
                if(rr >= 0 && rr < nr && cc >= 0 && cc < nc && mat[rr][cc] == 1 && vis[rr][cc] == 0) {
                    que.push({{rr, cc}, tt+1});
                    vis[rr][cc] = 1;
                }
            }
            
        }
        
        if(fresh != cnFresh) return -1;
        
        
           
        return time;
    }
};
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int m, n;
    void dfs(int r, int c, vector<vector<bool>>&visited, int &temp, vector<vector<int>>& grid) {
        ++temp;
        visited[r][c] = true;
        for(int i = 0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if(visited[nr][nc]) continue;
            if(grid[nr][nc] == 0) continue;
            dfs(nr, nc, visited, temp, grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        int ans = 0;
        for(int i = 0; i<m; ++i) {
            for(int j = 0; j<n; ++j) {
                int temp = 0;
                if(grid[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j, visited, temp, grid);
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};


int main() {
    Solution solution;
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout<<solution.maxAreaOfIsland(grid)<<endl;
}
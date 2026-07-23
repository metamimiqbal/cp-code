#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int orginal) {
        image[sr][sc] = color;
        for(int i = 0; i<4; i++) {
            int r = sr + dr[i];
            int c = sc + dc[i];
            if(r < 0 || r >= m || c < 0 || c >= n) continue;
            if(image[r][c] == color || image[r][c] != orginal) continue; 
            //saving originality
            dfs(image, r, c, color, orginal);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        // vector<vector<bool>>visited(m, vector<bool>(n, false));
        int orginal = image[sr][sc];
        dfs(image, sr, sc, color, orginal);
        return image;
    }
}; 


int main(){
    Solution solution;
    int sr = 1;
    int sc = 1;
    vector<vector<int>>image {{1,1,1},{1,1,0},{1,0,1}};
    int color = 3;

    vector<vector<int>>ans = solution.floodFill(image, sr, sc, color);

    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

}
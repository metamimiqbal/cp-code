#include<bits/stdc++.h>
using namespace std;
void knapsack(){
    int W,n;
    cout<<"Input: \n";
    cin>>W>>n;
    vector<int> val(n),wt(n);
    for(int i = 0; i<n; i++)
        cin>>val[i];
    for(int i = 0; i<n; i++)
        cin>>wt[i];
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=W; j++){
            int valu = val[i-1];
            int wet = wt[i-1];
            if(j>=wet)
                dp[i][j]=max(dp[i-1][j-wet]+valu,dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<"Output: \n"<<dp[n][W]<<'\n';
}
signed main(){
    knapsack();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void lis(){
    int n;
    cout<<"Input: \n";
    cin>>n;
    vector<int> a(n),dp(n,1);
    for(int i = 0; i<n; i++)
        cin>>a[i];

    for(int i = 1; i<n; i++){
        for(int j = 0;j<i;j++){
            if(a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    cout<<"Output: \n"<<*max_element(dp.begin(),dp.end())<<'\n';
}

signed main(){
    lis();
    return 0;
}

/*
Input: 
8
10 9 2 5 3 7 101 18
Output: 
4
*/
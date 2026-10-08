#include<bits/stdc++.h>
using namespace std;

void shortest_distance(){
    int V;
    cout<<"Input: \n";
    cin>>V;
    vector<vector<int>> vec(V,vector<int>(V));
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++)
            cin>>vec[i][j];
    }

    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(vec[i][j]==-1)
                vec[i][j]=1e9;
        }
    }

    for(int k = 0; k<V; k++){
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++)
                vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
        }
    }

    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(vec[i][j]==1e9)
                vec[i][j]=-1;
        }
    }

    cout<<"Output: \n";
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++)
            cout<<vec[i][j]<<" ";
        cout<<'\n';
    }
}

signed main(){
    shortest_distance();
    return 0;
}
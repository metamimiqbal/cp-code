#include <bits/stdc++.h>
using namespace std;

int averageWaitingTime(vector<int>& executionTime) {
    int n = executionTime.size();

    sort(executionTime.begin(), executionTime.end());

    int timer = 0;
    int waitingTime = 0;

    for (int i = 0; i < n; i++) {
        cout<<"previous timer: "<<timer<<endl;
        waitingTime += timer;
        cout<<"wating timer: watingtime+=timer: "<<waitingTime<<endl;
        
        timer += executionTime[i];
        cout<<"latest timer: "<<timer<<endl<<endl;
    }

    return waitingTime / n;
}

int main() {
    int n; cin>>n;
    vector<int> vec(n);
    for(auto &u: vec) cin>>u;
    cout<<averageWaitingTime(vec)<<endl;
}
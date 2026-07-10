#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int>pq; // by default max heap
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(100);

    while(!pq.empty()) {
        cout<<pq.top()<<endl;
        pq.pop();
    }

    cout<<endl;

    priority_queue<int, vector<int>, greater<int>>minpq; // by default max heap
    minpq.push(10);
    minpq.push(50);
    minpq.push(20);
    minpq.push(100);

    while(!minpq.empty()) {
        cout<<minpq.top()<<endl;
        minpq.pop();
    }
}
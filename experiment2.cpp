#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl endl
#define spc " " 

bool cmp(pair<int, int>a, pair<int, int>b) {
    if(a.first != b.first) return a.first < b.first;
    else return a.second > b.second;
}

bool comp(string a, string b) {
    if(a.size() != b.size()) return a.size() < b.size();
    else return a < b;
}

int main(){
    vector<pair<int,int>>vec = {
        {5, 1},
        {5, 2},
        {5, 3},
        {5, 4},
        {5, 5}
    };

    
    vector<string> v = {"banana", "fig", "apple", "date", "kiwi", "date"};
    
    // sort(v.begin(), v.end(), comp);
    sort(v.begin(), v.end(), [](const string &a, const string &b){
        if(a.size() != b.size()) return a.size() < b.size();
        else return a < b;
    }
);

    sort(vec.begin(), vec.end(), cmp);
    for(auto [u, v]: vec) {
        cout<<u<<spc<<v<<nl;
    }
    cout<<nl;

    cout<<"sorted string: \n";
    for(auto s: v) cout<<s<<spc; 
    cout<<nl;

    if(is_sorted(vec.begin(), vec.end(), cmp)){
        cout<<"Yahoo\n";
    }else{
        cout<<"Nahoo\n";
    }

    return 0;
}
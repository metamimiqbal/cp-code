#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl endl
#define spc " " 

int main(){
    vector<ll>vec = {11, 1, 2, 3};
    // vec.erase(vec.end()-1);
    vec.erase(vec.begin(), vec.end()-1);
    for(int i = 0; i<vec.size(); i++) cout<<vec[i]<<spc;
    cout<<nl;
    return 0;
}
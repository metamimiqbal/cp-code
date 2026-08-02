#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int>v{1, 21, 31, 31};

    int l = 0, r = v.size() - 1;
    int target = 21;
    while(l<=r) {
        int md = l + (r-l)/2;
        if(v[md] == target) {
            cout<<"at index: "<<md<<endl; return 0;
        }

        if(v[l] <= v[md]) {  // check: Is LEFT half sorted?
            if(v[l] <= target && target < v[md]) {
                r = md - 1;
            } else {
                l = md + 1;
            }
            
        } else { // check: if left not sorted, then right is obviously sorted!
            if(v[md] < target && target <= v[r]) {
                l = md + 1;
            } else {
                r = md - 1;
            }
        }
    }

    cout<<"Naire Bara\n";
    

    return 0;
}
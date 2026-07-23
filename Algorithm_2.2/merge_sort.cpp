#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>&left, vector<int>&right) {
    vector<int>merged;

    size_t l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if(left[l] <= right[r]) {
            merged.push_back(left[l]); ++l; 
        } else {
            merged.push_back(right[r]); ++r;
        }
    }
    while(l < left.size()) {
        merged.push_back(left[l]); ++l; 
    }
    while(r < right.size()) {
        merged.push_back(right[r]); ++r;
    }

    return merged;
}



// divide and conquer:
vector<int> merge_sort(vector<int>&vec) {
    if((int)vec.size() <= 1) return vec;

    int md = vec.size()/2;
    vector<int> left(vec.begin(), vec.begin() + md);
    vector<int> right(vec.begin() + md, vec.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}


int main() {
    vector<int> vec {5, 4, 3, 2, 1};

    vec = merge_sort(vec);

    for(auto u: vec) cout<<u<<" ";
    cout<<endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>&left, vector<int>&majhari, vector<int>&right) {
    vector<int>merged;

    size_t l = 0, r = 0, m = 0; 
    while(l < left.size() && r < right.size() && m < majhari.size()) {
        if(left[l] <= right[r]) {
            if(left[l] <= majhari[m]) {
                merged.push_back(left[l]); ++l; 
            } else{
                merged.push_back(majhari[m]); ++m;
            }
        } else {
            if(right[r] <= majhari[m]) {
                merged.push_back(right[r]); ++r;
            } else{
                merged.push_back(majhari[m]); ++m;
            }
        }
    }

    while(l < left.size() && r < right.size()) {
        if(left[l] <= right[r]) {
            merged.push_back(left[l]); ++l; 
        } else {
            merged.push_back(right[r]); ++r;
        }
    }
    while(l < left.size() && m < majhari.size()) {
        if(left[l] <= majhari[m]) {
            merged.push_back(left[l]); ++l; 
        } else {
            merged.push_back(majhari[m]); ++m;
        }
    }
    while(m < majhari.size() && r < right.size()) {
        if(majhari[m] <= right[r]) {
            merged.push_back(majhari[m]); ++m; 
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
    while(m < majhari.size()) {
        merged.push_back(right[m]); ++m;
    }


    return merged;
}

void print(vector<int> &vec) {
    for(auto u: vec) cout<<u<<" ";
    cout<<endl;
}


// divide and conquer:
vector<int> merge_sort(vector<int>&vec) {
    if((int)vec.size() <= 1) return vec;

    int md = max(1, (int)vec.size() / 3);
    vector<int> left(vec.begin(), vec.begin() + md);
    print(left);

    vector<int> mid(vec.begin() + md, vec.begin() + 2*md);
    print(mid);
    
    vector<int> right(vec.begin() + 2*md, vec.end());
    print(right);

    left = merge_sort(left);
    mid = merge_sort(mid);
    right = merge_sort(right);

    
    return merge(left, mid, right);
    // return merge(left, merge(mid, right));
}


int main() {
    vector<int> vec {8, 7, 6, 5, 4, 3, 2, 1};

    cout<<"main array: ";
    print(vec);

    vec = merge_sort(vec);

    for(auto u: vec) cout<<u<<" ";
    cout<<endl;

    return 0;
}
// counting sort, redix sort, bucket sort, quick sort

#include <bits/stdc++.h>
using namespace std;

vector<int> counting_sort(vector<int>&vec) {
    int n = *max_element(vec.begin(), vec.end());
    vector<int> freq(n+1), prefreq(n+1);
    int sz = vec.size();
    vector<int> ans(sz);

    for(int i = 0; i<sz; i++) freq[vec[i]]++;
    

    for(int i = 0; i<=n; i++) {
        if(i > 0) {
            prefreq[i] = prefreq[i-1] + freq[i];
        } else {
            prefreq[i] = freq[i];
        }
    }

    for(int i = sz-1; i>=0; i--) {
        ans[prefreq[vec[i]]-1] = vec[i];
    }

    return ans;
}


int main() {
    vector<int>vec{5, 4, 3, 2, 1};

    vector<int>output = counting_sort(vec);
    for(auto x: output) cout<<x<<" ";
    cout<<endl;

    return 0;
}
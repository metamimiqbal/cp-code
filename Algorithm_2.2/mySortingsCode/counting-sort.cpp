#include <bits/stdc++.h>
using namespace std;

vector<int> CountingSort(vector<int>&vec) {
    int mx = -1, n = vec.size();
    vector<int>ans(n);
    for(int i = 1; i<n; i++) {
        mx = max(mx, vec[i]);
    }

    vector<int>freq(mx+1), pfreq(mx+1);
    for(int i = 1; i<n; i++) {
        freq[vec[i]]++;
    }

    for(int i = 1; i<mx+1; i++) {
        pfreq[i] = pfreq[i-1] + freq[i];
    }


    for(int i = n-1; i>=1; --i) {
        ans[pfreq[vec[i]]] = vec[i];
        pfreq[vec[i]]--; 
    }

    return ans;
}



int main() {
    int n; cin>>n;
    vector<int>vec(n+1), ans(n+1);
    
    for(int i = 1; i<n+1; i++) {
        cin>>vec[i]; 
    }

    vec = CountingSort(vec);

    for(int i = 1; i<n+1; i++) cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}
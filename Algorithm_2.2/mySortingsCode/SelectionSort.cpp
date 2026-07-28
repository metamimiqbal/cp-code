#include<iostream>
#include<vector>
using namespace std;

vector<int> selectionSort(vector<int>vec) {
    int len = vec.size();
    int k = -1;
    for(int i = 0; i<len-1; i++) {
        int mn = INT8_MAX;
        for(int j = i+1; j<len; j++) {
            if(vec[j] <= mn) {
                mn = vec[j];
                k = j;
            }
        }
        // vec[i], vec[k] = vec[k], vec[i];
        swap(vec[i], vec[k]);
    }
    return vec;
}

int main() {    
    vector<int>v{5, 4, 0, 3, 2, 1};
    v = selectionSort(v);
    for(auto x: v) cout<<x<<" ";
    cout<<endl;
}
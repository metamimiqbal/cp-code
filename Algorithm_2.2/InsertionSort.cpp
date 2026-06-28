#include<iostream>
#include<vector>
using namespace std;

vector<int> inSertionSort(vector<int>vec) {
    int len = vec.size();
    for(int i = 0; i<len; i++) {
        int key = vec[i];
        int j = i-1;
        while(j>=0 and vec[j] > key) {
            vec[j+1] = vec[j];
            --j;
        }
        vec[j+1] = key;
    }
    return vec;
}

int main() {    
    vector<int>v{5, 4, 0, 3, 2, 1};
    v = inSertionSort(v);
    for(auto x: v) cout<<x<<" ";
    cout<<endl;
}
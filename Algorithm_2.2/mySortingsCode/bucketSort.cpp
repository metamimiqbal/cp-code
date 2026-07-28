#include <bits/stdc++.h>
using namespace std;

// void InsertionSort(vector<float>& v) {
//     //to use: InsertionSort(bucket[i]);
//     for(int i = 1; i < v.size(); i++) {
//         float x = v[i];
//         int j = i - 1;

//         while(j >= 0 && v[j] > x) {
//             v[j + 1] = v[j];
//             j--;
//         }

//         v[j + 1] = x;
//     }
// }



vector<float> BucketSort(vector<float>& vec) {
    int n = vec.size() - 1;

    // 10 buckets: B0 ... B9
    vector<vector<float>> bucket(10);

    // Distribution
    for(int i = 1; i <= n; i++) {
        int idx = (int)(vec[i] * 10);      // floor(value * 10)

        // Safety (if value == 1.0)
        if(idx == 10) idx = 9;

        bucket[idx].push_back(vec[i]);
    }

    // Sort each bucket
    for(int i = 0; i < 10; i++) {
        sort(bucket[i].begin(), bucket[i].end());
        // Abdul Bari uses Insertion Sort.
        // STL sort is used here for simplicity.
    }

    // Concatenate
    vector<float> ans(n + 1);
    int k = 1;

    for(int i = 0; i < 10; i++) {
        for(float x : bucket[i]) {
            ans[k++] = x;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<float> vec(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    vec = BucketSort(vec);

    for(int i = 1; i <= n; i++) {
        cout << fixed << setprecision(2) << vec[i] << " ";
    }

    cout << endl;

    return 0;
}
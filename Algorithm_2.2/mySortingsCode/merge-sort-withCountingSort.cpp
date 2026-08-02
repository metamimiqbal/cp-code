#include <bits/stdc++.h>
using namespace std;

// Counting Sort (works for non-negative integers)
vector<int> counting_sort(vector<int> &arr) {
    if (arr.empty()) return arr;

    int mx = *max_element(arr.begin(), arr.end());

    vector<int> freq(mx + 1, 0);

    for (int x : arr)
        freq[x]++;

    vector<int> sorted;
    sorted.reserve(arr.size());

    for (int i = 0; i <= mx; i++) {
        while (freq[i]--)
            sorted.push_back(i);
    }

    return sorted;
}

// Divide and Conquer
vector<int> merge_sort_counting(vector<int> &vec) {
    if (vec.size() <= 1)
        return vec;

    int mid = vec.size() / 2;

    vector<int> left(vec.begin(), vec.begin() + mid);
    vector<int> right(vec.begin() + mid, vec.end());

    left = merge_sort_counting(left);
    right = merge_sort_counting(right);

    // Instead of merge(), concatenate...
    vector<int> combined;
    combined.reserve(left.size() + right.size());

    combined.insert(combined.end(), left.begin(), left.end());
    combined.insert(combined.end(), right.begin(), right.end());

    // ...and Counting Sort the combined array.
    return counting_sort(combined); 
}

int main() {
    vector<int> vec = {5, 8, 1, 3, 7, 2, 4, 6};

    vec = merge_sort_counting(vec);

    for (int x : vec)
        cout << x << " ";
    cout << '\n';

    return 0;
}
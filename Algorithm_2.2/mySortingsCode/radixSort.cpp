#include <bits/stdc++.h>
using namespace std;

vector<int> RadixSort(vector<int> &vec) {
    int n = vec.size() - 1;

    int mx = -1;
    for(int i = 1; i <= n; i++) {
        mx = max(mx, vec[i]);
    }

    int divisor = 1;

    while(mx / divisor > 0) {

        vector<queue<int>> bins(10);

        // Put elements into bins
        for(int i = 1; i <= n; i++) {
            int digit = (vec[i] / divisor) % 10;
            bins[digit].push(vec[i]);
        }

        // Collect elements
        int idx = 1;
        for(int i = 0; i < 10; i++) {
            while(!bins[i].empty()) {
                vec[idx++] = bins[i].front();
                bins[i].pop();
            }
        }

        divisor *= 10;
    }

    return vec;
}

int main() {

    int n;
    cin >> n;

    vector<int> vec(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    vec = RadixSort(vec);

    for(int i = 1; i <= n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
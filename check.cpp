#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int bit = 0; bit < 32; bit++) {
        int cnt = 0;

        for (int x : nums) {
            if (x & (1 << bit)) {
                cnt++;
            }
        }

        if (cnt % 3 != 0) {
            ans |= (1 << bit);
            cout<<bit<<endl;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 2, 2, 5, 5, 5, 9};

    cout << singleNumber(nums) << '\n';

    return 0;
}
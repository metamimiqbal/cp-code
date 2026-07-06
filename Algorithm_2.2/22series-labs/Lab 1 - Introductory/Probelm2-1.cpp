// Binary Search
#include <bits/stdc++.h>
using namespace std;

int main () {
    vector <int> a = {152,177,162,151,181,174};
    int size = a.size();

    for (int i = 0; i < size; i++) {
        
        for (int j = i+1; j < size; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "Number: "; int x;
    cin >> x; int flag = 0;
    int l = 0, r = size-1;
    while (l <= r) { // binary search
        int mid = (l+r)/2;
        if (x < a[mid]) {
            r = mid;
        } else if (x > a[mid]) {
            l = mid+1;
        } else {
            cout << "Found at index " << mid << endl; flag = 1;
            break;
        }
    } if (flag == 0) cout << "Not Found" << endl;
}

// Time Complexity: O(logn)
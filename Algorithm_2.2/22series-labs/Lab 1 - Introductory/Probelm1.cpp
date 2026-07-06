// Linear Search
#include <bits/stdc++.h>
using namespace std;

int main () {
    vector <int> a = {152,177,162,151,181,174};
    int size = a.size();
    cout << "Number: "; int x;
    cin >> x; int flag = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == x) {
            cout << "Found at index " << i << endl; 
            flag = 1; break;
        }
    } if (flag == 0) cout << "Not Found" << endl;
}

// Time Complexity: O(n)
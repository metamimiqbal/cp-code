#include <bits/stdc++.h>
using namespace std;

int main () {
    vector <int> a = {152,177,162,151,181,174};
    cout << "Number: "; int x;
    cin >> x; int flag = 0;
    map <int,int> m;
    for (auto i : a) {
        m[i] = 1;
    }
    if (m[x]) cout << "Found" << endl;
    else cout << "Not Found" << endl;
}

// Time Complexity: O(1)
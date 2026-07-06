#include <bits/stdc++.h>
using namespace std;

bool comp (tuple<int,int,float> t1, tuple<int,int,float> t2) {
    if (get<2>(t1) > get<2>(t2)) return true;
    else return false;
}

int main() {
    cout << "How many objects: ";
    int n; cin >> n;
    cout << "Knapsack Weight: ";
    int k; cin >> k;
    vector <tuple<int,int,float>> v(n);
    cout << "Input the corresponding WEIGHTS of the objects:" << endl;
    for (int i = 0; i < n; i++) cin >> get<1>(v[i]);
    cout << "Input the corresponding PROFITS of the objects:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> get<0>(v[i]);
        get<2>(v[i]) = (float)get<0>(v[i]) / get<1>(v[i]);
    }
    cout << "Profit / Weight: " << endl;
    for (int i = 0; i < n; i++) cout << get<2>(v[i]) << " ";
    cout << endl;
    sort(v.begin(), v.end(), comp);
    float profit = 0; int i = 0;
    while (k || (i < n)) {
        if ((k - get<1>(v[i])) < 0) {
            profit += get<2>(v[i])*k; k = 0;
        } else {
            profit += get<0>(v[i]);
            k -= get<1>(v[i]);
        } i++;
    } 
    cout << "Maximum Profit: " << profit << endl;
}
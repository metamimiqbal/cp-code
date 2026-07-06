#include <bits/stdc++.h>
using namespace std;

// profit, deadline, number
bool comp (tuple<int,int,int> p1, tuple<int,int,int> p2) {
    if (get<0>(p1) > get<0>(p2)) return true;
    else return false;
}

int main() {
    cout << "How many jobs: ";
    int n; cin >> n;
    vector <tuple<int,int,int>> v(n);
    for (int i = 0; i < n; i++) get<2>(v[i]) = i+1;
    cout << "Input the corresponding DEADLINES of the jobs:" << endl;
    for (int i = 0; i < n; i++) cin >> get<1>(v[i]);
    cout << "Input the corresponding PROFITS of the jobs:" << endl;
    for (int i = 0; i < n; i++) cin >> get<0>(v[i]);
    sort(v.begin(), v.end(), comp);
    int max_deadline = -1;
    for (int i = 0; i < n; i++) {
        max_deadline = (get<1>(v[i]) > max_deadline) ? get<1>(v[i]) : max_deadline;
    }
    vector <tuple<int,int,int>> slots(max_deadline);
    for (int i = 0; i < n; i++) {
        for (int j = get<1>(v[i])-1; j >= 0; j--) {
            if (get<0>(slots[j]) == 0 && get<1>(slots[j]) == 0) {
                slots[j] = v[i];
                break;
            }
        }
    }
    cout << endl << "Doable Jobs: " << endl;
    int profit = 0;
    for (int i = 0; i < max_deadline; i++)  {
        cout << "Slot " << i+1 << ": " << "Job " << get<2>(slots[i]) << endl;
        profit += get<0>(slots[i]);
    } 
    cout << "Maximum Profit:" << " " << profit << endl;
}
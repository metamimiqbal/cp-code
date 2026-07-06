#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int mid, int r) {
    int a = l;
    int b = mid;
    int temp[r-l], p = 0;
    while (a < mid &&  b < r) {
        if (v[a] < v[b]) {
            temp[p] = v[a];
            a++; p++;
        } else {
            temp[p] = v[b];
            b++; p++;
        }
    } while (a < mid) {
        temp[p] = v[a];
        p++; a++;
    } while (b < r) {
        temp[p] = v[b];
        p++; b++;
    } p = 0; 
    for (int i = l; i < r; i++) {
        v[i] = temp[p];
        p++;
    }
}

void mergesort(vector<int> &v, int l, int r) {
    if ((r - l) <= 1) return;
    int mid = (l+r)/2;
    mergesort(v, l, mid);
    mergesort(v, mid, r);
    merge(v,l,mid,r);
}

int main() {
    vector<int> v = {159, 152, 177, 172, 174};

    mergesort(v,0,5);
    for (auto &i : v) {
        cout << i << " ";
    }
}
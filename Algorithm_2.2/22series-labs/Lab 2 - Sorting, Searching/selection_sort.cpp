#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {159, 152, 177, 172, 174};

    for (int i = 0; i < 5; i++) {
        int min = arr[i]; int index = i;
        for (int j = i; j < 5; j++) {
            if (arr[j] < min) {
                min = arr[j]; index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}

// f(n) = n * n = n2

// n2 <= n2 : O(n2)
// n2 >= -n2 : Omega(n2)
// -n2 <= n2 <= n2 : Theta(n2)
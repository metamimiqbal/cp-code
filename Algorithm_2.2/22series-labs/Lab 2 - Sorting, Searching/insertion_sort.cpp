#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {159, 152, 177, 172, 174};

    for (int i = 1; i < 5; i++) {
        for (int j = i-1; j >= 0; j++) {
            int temp = arr[i];
            if (temp < arr[j]) {
                arr[j+1] = arr[j];
                arr[j] = temp;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}

// f(n) = (n-1) * (n-2) = n2 - 3n - 3

// n2 - 3n - 3 <= n2 : O(n2)
// n2 - 3n - 3 >= -n2 : Omega(n2)
// -n2 <= n2 - 3n + 3 <= n2 : Theta(n2)
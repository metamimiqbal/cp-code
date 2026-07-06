#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {159, 152, 177, 172, 174};

    for (int i = 0; i < 5; i++) { // 5 times
        for (int j = 0; j < 4-i; j++) { // 
            if (arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}

// f(n) = n * (n-1) = n2 - n

// n2 - n <= n2 : O(n2)
// -n2 <= n2 - n1 : Omega(n2)
// -n2 <= n2 - n1 <= n2 : Theta(n2)
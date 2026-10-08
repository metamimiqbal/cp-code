#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define flt long double

int main() {
    int n;
    cin >> n;

    vector<flt> x(n), y(n);

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    flt h = x[1] - x[0];

    vector<vector<flt>> D(n, vector<flt>(n, 0));

    for (int i = 0; i < n; i++)
        D[0][i] = y[i];

    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n - k; i++) {
            D[k][i] = D[k - 1][i + 1] - D[k - 1][i];
        }
    }

    cout << fixed << setprecision(6);

    cout << "\nDifference Table:\n";

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n - i; k++) {
            cout << setw(12) << D[k][i];
        }
        cout << '\n';
    }

    int b;
    cin >> b;

    int m = min(b, n - 1 - b);

    vector<flt> alpha = {
        1.0L,
        -1.0L / 6,
        1.0L / 30
    };


    vector<flt> beta = {
        1.0L,
        -1.0L / 12,
        1.0L / 90
    };

    flt s1 = 0;
    flt s2 = 0;

    for (int j = 1; j <= 3 && 2 * j - 1 <= m; j++) {
        int k = 2 * j - 1;

        flt avg = (
            D[k][b - j] +
            D[k][b - j + 1]
        ) / 2.0L;

        s1 += alpha[j - 1] * avg;
    }

    for (int j = 1; j <= 3 && 2 * j <= m + 1; j++) {
        int k = 2 * j;

        s2 += beta[j - 1] * D[k][b - j];
    }

    flt dy = s1 / h;
    flt d2y = s2 / (h * h);

    cout << "\nAt x = " << x[b] << '\n';
    cout << "dy/dx   = " << dy << '\n';
    cout << "d2y/dx2 = " << d2y << '\n';

    return 0;
}
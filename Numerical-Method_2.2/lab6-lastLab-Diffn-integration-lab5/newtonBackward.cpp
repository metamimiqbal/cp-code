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

    int b, K;
    cin >> b >> K;

    flt s1 = 0;

    for (int k = 1; k <= K; k++) {
        flt nabla = D[k][b - k];
        s1 += nabla / k;
    }

    vector<flt> c2 = {
        1.0L,
        1.0L,
        11.0L / 12,
        5.0L / 6,
        137.0L / 180
    };

    flt s2 = 0;

    for (int k = 2; k <= K; k++) {
        flt nabla = D[k][b - k];
        s2 += c2[k - 2] * nabla;
    }

    flt dy = s1 / h;
    flt d2y = s2 / (h * h);

    cout << "\nAt x = " << x[b] << '\n';
    cout << "dy/dx   = " << dy << '\n';
    cout << "d2y/dx2 = " << d2y << '\n';

    return 0;
}
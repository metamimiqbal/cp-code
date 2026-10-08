#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define flt long double

int main()
{
    int n;
    flt a, b;
    cin >> a;
    cin >> b;
    cin >> n;
    flt h = (b - a) / n;
    vector<flt> x(n + 1), y(n + 1);
    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;
        cin >> y[i];
    }
    flt sum = y[0] + y[n];
    for (int i = 1; i < n; i++)
    {
        int weight = 2;
        sum += weight * y[i];
    }
    flt I = (h / 2.0) * sum;
    cout << "Integral = " << I << '\n';

    return 0;
}

/*
testcase for trapizoidal - ensure just the output, not this comment itself in the report
0
1
4
1
0.8
0.6666667
0.5714286
0.5
*/
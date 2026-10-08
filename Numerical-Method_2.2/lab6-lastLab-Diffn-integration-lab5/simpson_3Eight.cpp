#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define flt long double

int main()
{
    int n;
    flt a, b;

    cin>>a>>b>>n;

    if (n % 3 != 0)
    {
        return 0;
    }

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
        int weight;
        if (i % 3 == 0) weight = 2;
        else weight = 3;
        sum += weight * y[i];
    }


    flt I = (3.0 * h / 8.0) * sum;

    cout << "Integral = " << I << '\n';

    return 0;
}

/*
testcase for simpson-3/8
0
1
6
1
0.8571429
0.75
0.6666667
0.6
0.5454545
0.5
*/
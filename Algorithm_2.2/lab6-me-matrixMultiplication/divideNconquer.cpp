#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define flt long double
#define VEC vector<ll>
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define rrep(i, a, b) for(ll i = (a); i>=(b); --i)
#define each(x, a) for(auto &x: (a))

vector<vector<ll>> addMatrix(const vector<vector<ll>>&a, const vector<vector<ll>>&b) {
    ll n = a.size();
    vector<vector<ll>>c(n, vector<ll>(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

vector<vector<ll>> sliceMatrix(const vector<vector<ll>>&a, ll rowStart, ll colStart, ll size) {
    vector<vector<ll>>part(size, vector<ll>(size));
    rep(i, 0, size) {
        rep(j, 0, size) {
            part[i][j] = a[rowStart + i][colStart + j];
        }
    }
    return part;
}

vector<vector<ll>> combineMatrix(const vector<vector<ll>>&c11, const vector<vector<ll>>&c12,
    const vector<vector<ll>>&c21,
    const vector<vector<ll>>&c22) 
{
    ll half = c11.size();
    ll n = half * 2;
    vector<vector<ll>>c(n, vector<ll>(n));

    rep(i, 0, half) {
        rep(j, 0, half) {
            c[i][j] = c11[i][j];
            c[i][j + half] = c12[i][j];
            c[i + half][j] = c21[i][j];
            c[i + half][j + half] = c22[i][j];
        }
    }
    return c;
}

vector<vector<ll>> matrixMultiplyRec(const vector<vector<ll>>&a, const vector<vector<ll>>&b, ll n) {
    if(n == 1) {
        return {{a[0][0] * b[0][0]}};
    }

    ll half = n / 2;

    vector<vector<ll>>a11 = sliceMatrix(a, 0, 0, half);
    vector<vector<ll>>a12 = sliceMatrix(a, 0, half, half);
    vector<vector<ll>>a21 = sliceMatrix(a, half, 0, half);
    vector<vector<ll>>a22 = sliceMatrix(a, half, half, half);

    vector<vector<ll>>b11 = sliceMatrix(b, 0, 0, half);
    vector<vector<ll>>b12 = sliceMatrix(b, 0, half, half);
    vector<vector<ll>>b21 = sliceMatrix(b, half, 0, half);
    vector<vector<ll>>b22 = sliceMatrix(b, half, half, half);

    vector<vector<ll>>c11 = addMatrix(
        matrixMultiplyRec(a11, b11, half),
        matrixMultiplyRec(a12, b21, half)
    );
    vector<vector<ll>>c12 = addMatrix(
        matrixMultiplyRec(a11, b12, half),
        matrixMultiplyRec(a12, b22, half)
    );
    vector<vector<ll>>c21 = addMatrix(
        matrixMultiplyRec(a21, b11, half),
        matrixMultiplyRec(a22, b21, half)
    );
    vector<vector<ll>>c22 = addMatrix(
        matrixMultiplyRec(a21, b12, half),
        matrixMultiplyRec(a22, b22, half)
    );
    return combineMatrix(c11, c12, c21, c22);
}

vector<vector<ll>> divideNconquerMatrixMultiplication(vector<vector<ll>>&x, vector<vector<ll>>&y) 
{
    ll n = x.size();
    if(n == 0 || (ll)y.size() != n) return {};

    rep(i, 0, n) {
        if((ll)x[i].size() != n || (ll)y[i].size() != n) return {};
    }

    ll m = 1;
    while(m < n) m <<= 1;

    vector<vector<ll>>a(m, vector<ll>(m, 0)), b(m, vector<ll>(m, 0));
    rep(i, 0, n) {
        rep(j, 0, n) {
            a[i][j] = x[i][j];
            b[i][j] = y[i][j];
        }
    }

    vector<vector<ll>>full = matrixMultiplyRec(a, b, m);
    vector<vector<ll>>ans(n, vector<ll>(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            ans[i][j] = full[i][j];
        }
    }
    return ans;
}

int main() {
    vector<vector<ll>>v1{{1, 2, 3}, {2, 3, 4}, {3, 4, 5}}, v2{{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
    ll n = v1.size();

    vector<vector<ll>>rslt = divideNconquerMatrixMultiplication(v1, v2);

    rep(i, 0, n) {
        rep(j, 0, n) {
            cout<<rslt[i][j]<<" ";
        }
        cout<<"\n";
    }
}

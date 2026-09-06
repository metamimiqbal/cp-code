#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define flt long double
#define VEC vector<ll>
#define Matrix vector<vector<ll>>
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for(ll i = (a); i<(b); ++i)
#define rrep(i, a, b) for(ll i = (a); i>=(b); --i)
#define each(x, a) for(auto &x: (a))

Matrix add(const Matrix &A, const Matrix &B) {
    ll n = A.size();
    Matrix rslt(n, vector<ll>(n));
    rep(i, 0, n) {
        rep(j, 0, n) rslt[i][j] = A[i][j] + B[i][j];
    }
    return rslt;
}

Matrix sub(const Matrix &A, const Matrix &B) {
    ll n = A.size();
    Matrix rslt(n, vector<ll>(n));
    rep(i, 0, n) {
        rep(j, 0, n) rslt[i][j] = A[i][j] - B[i][j];
    }
    return rslt;
}


Matrix mul(Matrix A, Matrix B) {
    ll n = A.size();

    if(n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    ll md = n/2;

    Matrix a11(md, vector<ll>(md)), a12(md, vector<ll>(md)),
           a21(md, vector<ll>(md)), a22(md, vector<ll>(md)),
           b11(md, vector<ll>(md)), b12(md, vector<ll>(md)),
           b21(md, vector<ll>(md)), b22(md, vector<ll>(md));

    rep(i, 0, md) {
        rep(j, 0, md) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][md+j];
            a21[i][j] = A[i+md][j];
            a22[i][j] = A[i+md][j+md];
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            b11[i][j] = B[i][j];
            b12[i][j] = B[i][md+j];
            b21[i][j] = B[i+md][j];
            b22[i][j] = B[i+md][j+md];
        }
    }


    Matrix M1 = mul(a11, sub(b12, b22));
    Matrix M2 = mul(add(a11, a12), b22);
    Matrix M3 = mul(add(a21, a22), b11);
    Matrix M4 = mul(a22, sub(b21, b11));
    Matrix M5 = mul(add(a11, a22), add(b11, b22));
    Matrix M6 = mul(sub(a12, a22), add(b21, b22));
    Matrix M7 = mul(sub(a11, a21), add(b11, b12));
    Matrix c11 = add(sub(add(M5, M4), M2), M6);
    Matrix c12 = add(M1, M2);
    Matrix c21 = add(M3, M4);
    Matrix c22 = sub(sub(add(M5, M1), M3), M7);

    Matrix c(n, vector<ll>(n));

    rep(i, 0, md) {
        rep(j, 0, md) {
            c[i][j] = c11[i][j];
            c[i][j+md] = c12[i][j];
            c[i+md][j] = c21[i][j];
            c[i+md][j+md] = c22[i][j];
        }
    }

    return c;
}

int main() {
    Matrix a = {{1, 2, 3, 4}, {2, 3, 4, 5}, {4, 5, 6, 7}, {2, 6, 7, 8}},
    b = {{2, 3, 4, 5}, {1, 2, 3, 4}, {4, 5, 6, 7}, {2, 6, 7, 8}};

    Matrix ans = mul(a, b);

    for(auto u: ans) {
        for(auto x: u) cout<<x<<" ";
        cout<<endl;
    }
}
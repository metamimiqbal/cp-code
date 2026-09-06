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


Matrix mul(Matrix A, Matrix B) {
    ll n = A.size();
    if(n == 1) {
        return {{A[0][0] * B[0][0]}};
    }


    ll md = n/2;
    Matrix a11(md, vector<ll>(md)), a12(md, vector<ll>(md)), a21(md, vector<ll>(md)), a22(md, vector<ll>(md)), b11(md, vector<ll>(md)), b12(md, vector<ll>(md)), b21(md, vector<ll>(md)), b22(md, vector<ll>(md));

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

    Matrix c11(md, vector<ll>(md)), c12(md, vector<ll>(md)), c21(md, vector<ll>(md)), c22(md, vector<ll>(md));

    c11 = add(mul(a11, b11), mul(a12, b21));
    c12 = add(mul(a11, b12), mul(a12, b22));
    c21 = add(mul(a21, b11), mul(a22, b21));
    c22 = add(mul(a21, b12), mul(a22, b22));

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


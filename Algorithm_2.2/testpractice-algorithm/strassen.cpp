// d&c matrix multiplication:
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
#define nl "\n"
#define spc " "
#define Matrix vector<vector<ll>>

Matrix add(const Matrix &a, const Matrix &b) {
    ll n = a.size(); // assuming square matrix
    Matrix c(n, vector<ll>(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }   
    return c;
}
Matrix sub(const Matrix &a, const Matrix &b) {
    ll n = a.size(); // assuming square matrix
    Matrix c(n, vector<ll>(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }   
    return c;
}


Matrix mul(const Matrix &a, const Matrix &b) {
    ll n = a.size(); // assuming square matrix
    ll md = n/2;
    if(n==1) {
        return Matrix{{a[0][0]*b[0][0]}};
    }

    Matrix a11(md, vector<ll>(md)), a12(md, vector<ll>(md)), a21(md, vector<ll>(md)),
    a22(md, vector<ll>(md)), b11(md, vector<ll>(md)), b12(md, vector<ll>(md)), 
    b21(md, vector<ll>(md)), b22(md, vector<ll>(md));

    rep(i, 0, md) {
        rep(j, 0, md) {
            a11[i][j] = a[i][j];
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            a12[i][j] = a[i][j+md];
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            a21[i][j] = a[i+md][j];
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            a22[i][j] = a[i+md][j+md]; 
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            b11[i][j] = b[i][j];
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            b12[i][j] = b[i][j+md];
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            b21[i][j] = b[i+md][j];
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            b22[i][j] = b[i+md][j+md]; 
        }
    }

    Matrix c11(md, vector<ll>(md)), c12(md, vector<ll>(md)), c21(md, vector<ll>(md)), c22(md, vector<ll>(md));

    Matrix m1(md, vector<ll>(md)), m2(md, vector<ll>(md)), m3(md, vector<ll>(md)), m4(md, vector<ll>(md)),
    m5(md, vector<ll>(md)), m6(md, vector<ll>(md)), m7(md, vector<ll>(md));
    
    m1 = mul(add(a11, a22), add(b11, b22));
    m2 = mul(b11, add(a21, a22));
    m3 = mul(a11, sub(b12, b22));
    m4 = mul(a22, sub(b21, b11));
    m5 = mul(b22, add(a11, a12));
    m6 = mul(sub(a21, a11), add(b11, b12));
    m7 = mul(sub(a12, a22), add(b21, b22));


    c11 = sub(add(add(m1, m4), m7), m5);
    c12 = add(m3, m5);
    c21 = add(m2, m4);
    c22 = sub(add(m1, add(m3, m6)), m2);


    Matrix c(n, vector<ll>(n));
    rep(i, 0, md) {
        rep(j, 0, md) {
            c[i][j] = c11[i][j];
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            c[i][j+md] = c12[i][j];
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            c[i+md][j] = c21[i][j];
        }
    }

    rep(i, 0, md) {
        rep(j, 0, md) {
            c[i+md][j+md] = c22[i][j];
        }
    }   

    return c;
}


int main() {
    Matrix a = {
        {1, 2},
        {3, 4}
    };

    Matrix b = {
        {5, 6},
        {7, 8}
    };

    Matrix c = mul(a, b);

    for(auto &row : c) {
        for(auto &x : row) {
            cout << x << spc;
        }
        cout << nl;
    }
}
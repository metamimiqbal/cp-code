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

vector<vector<ll>> subMatrix(const vector<vector<ll>>&a, const vector<vector<ll>>&b) {
	ll n = a.size();
	vector<vector<ll>>c(n, vector<ll>(n));
	rep(i, 0, n) {
		rep(j, 0, n) {
			c[i][j] = a[i][j] - b[i][j];
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

vector<vector<ll>> combineMatrix(
	const vector<vector<ll>>&z11,
	const vector<vector<ll>>&z12,
	const vector<vector<ll>>&z21,
	const vector<vector<ll>>&z22
) {
	ll half = z11.size();
	ll n = half * 2;
	vector<vector<ll>>z(n, vector<ll>(n));

	rep(i, 0, half) {
		rep(j, 0, half) {
			z[i][j] = z11[i][j];
			z[i][j + half] = z12[i][j];
			z[i + half][j] = z21[i][j];
			z[i + half][j + half] = z22[i][j];
		}
	}
	return z;
}

vector<vector<ll>> strassenRec(const vector<vector<ll>>&x, const vector<vector<ll>>&y, ll n) {
	if(n == 1) {
		return {{x[0][0] * y[0][0]}};
	}

	ll half = n / 2;

	vector<vector<ll>>x11 = sliceMatrix(x, 0, 0, half);
	vector<vector<ll>>x12 = sliceMatrix(x, 0, half, half);
	vector<vector<ll>>x21 = sliceMatrix(x, half, 0, half);
	vector<vector<ll>>x22 = sliceMatrix(x, half, half, half);

	vector<vector<ll>>y11 = sliceMatrix(y, 0, 0, half);
	vector<vector<ll>>y12 = sliceMatrix(y, 0, half, half);
	vector<vector<ll>>y21 = sliceMatrix(y, half, 0, half);
	vector<vector<ll>>y22 = sliceMatrix(y, half, half, half);

	vector<vector<ll>>xr1 = addMatrix(x11, x12);
	vector<vector<ll>>xr2 = addMatrix(x21, x22);
	vector<vector<ll>>xc1 = subMatrix(x11, x21);
	vector<vector<ll>>xc2 = subMatrix(x12, x22);
	vector<vector<ll>>xd1 = addMatrix(x11, x22);

	vector<vector<ll>>yc1 = subMatrix(y11, y21);
	vector<vector<ll>>yc2 = subMatrix(y12, y22);
	vector<vector<ll>>yr1 = addMatrix(y11, y12);
	vector<vector<ll>>yr2 = addMatrix(y21, y22);
	vector<vector<ll>>yd1 = addMatrix(y11, y22);

	vector<vector<ll>>p11 = strassenRec(x11, yc2, half);
	vector<vector<ll>>p22 = strassenRec(x22, yc1, half);
	vector<vector<ll>>pr1 = strassenRec(xr1, y22, half);
	vector<vector<ll>>pr2 = strassenRec(xr2, y11, half);
	vector<vector<ll>>pc1 = strassenRec(xc1, yr1, half);
	vector<vector<ll>>pc2 = strassenRec(xc2, yr2, half);
	vector<vector<ll>>pd1 = strassenRec(xd1, yd1, half);

	vector<vector<ll>>z11 = subMatrix(addMatrix(pd1, pc2), addMatrix(pr1, p22));
	vector<vector<ll>>z12 = addMatrix(p11, pr1);
	vector<vector<ll>>z21 = subMatrix(pr2, p22);
	vector<vector<ll>>z22 = subMatrix(subMatrix(addMatrix(pd1, p11), pc1), pr2);

	return combineMatrix(z11, z12, z21, z22);
}

vector<vector<ll>> strassenMatrixMultiplication(vector<vector<ll>>&x, vector<vector<ll>>&y) {
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

	vector<vector<ll>>full = strassenRec(a, b, m);
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

	vector<vector<ll>>x(n, vector<ll>(n)), y(n, vector<ll>(n));
	rep(i, 0, n) rep(j, 0, n) cin >> x[i][j];
	rep(i, 0, n) rep(j, 0, n) cin >> y[i][j];

	vector<vector<ll>>z = strassenMatrixMultiplication(x, y);

	rep(i, 0, n) {
		rep(j, 0, n) {
			cout << z[i][j] << (j + 1 == n ? '\n' : ' ');
		}
	}

	return 0;
}

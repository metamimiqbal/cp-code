#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl endl
#define spc " " 
#define printv(v)       for(auto x : v) cerr << x << ' '; cerr << nl

bool isPrimeBasic(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i*i<=n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

vector<ll> allDivisorsBasic(ll n) {
    vector<ll>divisorsbasic;
    for(ll i = 1; i*i<=n; i++) {
        if(n % i == 0) {
            divisorsbasic.push_back(i);
            if(n/i != i) divisorsbasic.push_back(n/i);
        }
    }
    sort(divisorsbasic.begin(), divisorsbasic.end());
    return divisorsbasic;
}

vector<ll> primeDivisorsBasic(ll n) {
    vector<ll>primeDivisors;
    for(ll i = 2; i*i<=n; i++) {
        if(n%i == 0) {
            primeDivisors.push_back(i);
            while(n%i == 0) n/=i;
        }
    }
    if(n!=1) primeDivisors.push_back(n);

    sort(primeDivisors.begin(), primeDivisors.end());
    return primeDivisors;
}

//nod, sod
//SOD -> SUM of all kinds of divisors of a number.
//NOD -> number of all kinds of divisors of a number.
ll NOD = -1;
ll SOD = -1;
ll powll(ll n, ll exp) {
    ll ans = 1;
    while(exp--) ans *= n;
    return ans;
}

void NOD_SOD(ll n) {
    vector<pair<ll, ll>>vpr;
    for(ll i = 2; i*i<=n; i++) {
        if(n%i == 0) {
            ll cn = 0;
            while(n%i == 0) {
                n/=i; cn++;
            }
            vpr.push_back({i, cn});
        }
    }
    if(n!=1) vpr.push_back({n, 1});

    ll nod = 1;
    for(auto [u, v]: vpr) nod *= (v+1);
    NOD = nod;

    ll sod = 1;
    for(auto [u, v]: vpr) {
        ll val = (powll(u, v+1)-1)/(u-1);
        sod *= val;
    }
    SOD = sod;
}


// primal range array
// bool arr[N+1] = {0};
ll N = 1e6;
vector<bool>vrange(N+1, true);

vector<ll> PrimeRange(ll n) {
    vector<ll>prime;
    vrange[0] = vrange[1] = false;
    for(ll i = 2; i<=n; i++) {
        if(vrange[i] == false) continue;
        prime.push_back(i);
        for(ll j = i*i; j<=n; j+=i) { 
            // cz j = i+i alread crosees out if been noticed!
            vrange[j] = false;
        }
    }
    return prime;
}


vector<ll> SPF(ll n) {
    vector<ll>spf(n+1);
    for(ll i = 1; i<=n; i++) spf[i] = i;
    for(ll i = 2; i<=n; i++) {
        if(spf[i] != i) continue;
        for(ll j = i+i; j<=n; j+=i) spf[j] = min(spf[j], i);
    }
    return spf;
}





int main(){
    ll x; cin>>x;
    // if(isPrimeBasic(x)) cout<<"Prime\n";
    // else cout<<"Not Prime\n";

    // vector<ll>divisors = allDivisorsBasic(x);
    // for(ll i = 0; i<divisors.size(); i++) cout<<divisors[i]<<spc; 
    // cout<<nl;

    // vector<ll>pdivisors = primeDivisorsBasic(x);
    // for(ll i = 0; i<pdivisors.size(); i++) cout<<pdivisors[i]<<spc; 
    // cout<<nl;
    
    // NOD_SOD(x);
    // cout<<NOD<<spc<<SOD<<nl;
    // vector<ll>vec = PrimeRange(x);
    // printv(vec);
    
    
    vector<ll>vec = SPF(x);
    printv(vec);

    return 0;
}
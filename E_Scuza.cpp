/*
This is the same dawn -- the one in which truth shall rise as falsehood falls.
By the promise of my Almighty, oppression shall perish, and justice shall prevail.

Free Palestine. Free the Uyghurs. Free the Rohingyas. 
Free Sudan, Yemen, Iraq, and every land where the blood of the innocent cries out.

They wish to extinguish the light of Allah with their mouths,
but Allah will perfect His light -- even if the disbelievers hate it.
-- Surah As-Saff (61:8)

And say: "Truth has come and falsehood has vanished.
Indeed, falsehood is bound to vanish."
-- Surah Al-Isra (17:81)

May Allah's curse be upon the oppressors, the tyrants, and the usurpers of truth.
May their plans be shattered as were those of Firaun, and their legacy buried like Aad and Thamud.

We stand with our oppressed brothers and sisters -- not with slogans, but with conviction.
Victory will surely come to those who stand firm upon the Haqq.

"So bear beautiful patience. They see it far off, but We see it near."
-- Surah Al-Ma'arij (70:5-7)

May mankind rise with justice, and may falsehood vanish -- as it is always bound to.
*/
#include <bits/stdc++.h>
using namespace std;
#define Ajkeo_Mara_Khamu_Bara ios::sync_with_stdio(false); cin.tie(nullptr);
#define nl '\n'
#define ll long long
#define ull unsigned long long
#define flt long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sum(x) accumulate(all(x), 0LL)
#define maxx(x) *max_element(all(x))
#define mpi map<int, int>
#define mps map<string, int>
#define seti set<int>
#define que queue<int>
#define dque deque<int>
#define prque priority_queue<int>  
#define aprque priority_queue<int, vector<int>, greater<int>>  
#define vec vector<ll>
#define vvec vector<vector<ll>>
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define spc " "
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define each(x,a) for(auto &x : a)
#define size(x) (int)(x).size()
#define gcd __gcd
#define lcm(a,b) ((a)/gcd(a,b)*(b))
#define mod 1000000007//1e9+7
#define modn(x) (((x)%mod+mod)%mod)
const int octroi = 1e7; 
// vector<int> dp(octroi, -1); 
// bitset<octroi> vc;

void solve(){
    int n, q; cin>>n>>q;
    vec v(n+1), prfx(n+1), mx(n+1);
    rep(i, 1, n+1){
        cin>>v[i];
        prfx[i] = v[i] + prfx[i-1];
        mx[i] = max(mx[i-1], v[i]);
    }
    while(q--){
        ll val; cin>>val;
        int idx = upper_bound(all(mx), val) - mx.begin();
        --idx;
        cout<<prfx[idx]<<" ";
    }
    cout<<nl;
}
signed main(){
    Ajkeo_Mara_Khamu_Bara
    int t; cin>>t; while(t--)
        solve();
   
    return 0;
}



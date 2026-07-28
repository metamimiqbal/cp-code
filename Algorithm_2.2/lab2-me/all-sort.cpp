
#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define THINK_LIKE_JACK_SPARROW FAST_IO

#define ll long long
#define flt long double
#define ull unsigned long long
#define VEC vector<ll>

vector<ll>org {5,2,8,1,4,3,2,7,5,9,6,0};
vector<ll>vec;

void cnt_sort() {
   ll mx = *max_element(vec.begin(),vec.end());

   vector<ll>cnt(mx+1,0);

   for(ll x : vec)
      cnt[x]++;

   ll id = 0;

   for(ll i = 0; i<=mx; i++) {
      while(cnt[i]--) {
         vec[id++] = i;
      }
   }
}


void bucket_sort() {
   ll mx = *max_element(vec.begin(),vec.end());

   ll bn = sqrt(vec.size());
   if(bn==0) bn = 1;

   vector<vector<ll>>buck(bn);

   for(ll x : vec) {
      ll id = (x*bn)/(mx+1);
      buck[id].push_back(x);
   }

   for(ll i = 0; i<bn; i++)
      sort(buck[i].begin(),buck[i].end());

   ll id = 0;

   for(ll i = 0; i<bn; i++) {
      for(ll x : buck[i])
         vec[id++] = x;
   }
}


void cnt_sort_digit(ll ex) {
   vector<ll>out(vec.size());
   vector<ll>cnt(10,0);

   for(ll x : vec)
      cnt[(x/ex)%10]++;

   for(ll i = 1; i<10; i++)
      cnt[i] += cnt[i-1];

   for(ll i = vec.size()-1; i>=0; i--) {
      ll d = (vec[i]/ex)%10;
      out[--cnt[d]] = vec[i];
   }

   vec = out;
}

void radix_sort() {
   ll mx = *max_element(vec.begin(),vec.end());

   for(ll ex = 1; mx/ex>0; ex*=10)
      cnt_sort_digit(ex);
}


void mergee(ll l,ll mid,ll r) {
   vector<ll>tmp ;

   ll i = l;
   ll j = mid+1;

   while(i<=mid&&j<=r) {
      if(vec[i]<=vec[j])
         tmp.push_back(vec[i++]);
      else
         tmp.push_back(vec[j++]);
   }

   while(i<=mid)
      tmp.push_back(vec[i++]);

   while(j<=r)
      tmp.push_back(vec[j++]);

   for(ll i = l,k = 0; i<=r; i++,k++)
      vec[i] = tmp[k];
}

void merge_sort(ll l,ll r) {
   if(l>=r) return;

   ll mid = (l+r)/2;

   merge_sort(l,mid);
   merge_sort(mid+1,r);

   mergee(l,mid,r);
}

k
void print_vec() {
   for(ll x : vec)
      cout<<x<<" ";
   cout<<'\n';
}

signed main() {
   THINK_LIKE_JACK_SPARROW

   vec = org;
   cnt_sort();
   cout<<"Counting Sort: ";
   print_vec();

   vec = org;
   bucket_sort();
   cout<<"Bucket Sort:   ";
   print_vec();

   vec = org;
   radix_sort();
   cout<<"Radix Sort:    ";
   print_vec();

   vec = org;
   merge_sort(0,vec.size()-1);
   cout<<"Merge Sort:    ";
   print_vec();

   return 0;
}
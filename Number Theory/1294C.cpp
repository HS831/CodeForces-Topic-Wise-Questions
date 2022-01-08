#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vector<ll> primeDiv(ll n) {
   v64 prime;
   for(ll i=2; i*i<=n; i++) {
       while(n%i==0) {
           prime.pb(i);
           n/=i;
       }
   }
   if(n>2) prime.pb(n);
   //for(auto &i:prime) cout<<i<<" ";
   //cout<<ln;
   return prime;

}

void solve()
{
  ll n,j;
  cin>>n;
  v64 a = primeDiv(n);
  v64 ans;
  if(a.size()<=2 || n<=22) {cout<<"NO"; return; }
  ans.pb(a[0]);
  if(a[0]==a[1]) { ans.pb(a[1]*a[2]); j = 3; }
  else { ans.pb(a[1]); j = 2; }
  ll p = 1;
  for(ll i=j; i<a.size(); i++) {
      p*=a[i];
  }
  if(p>1) ans.pb(p);
  sort(all(ans));
  ans.erase(unique(begin(ans),end(ans)),end(ans));
  if(ans[2]==ans[1] || ans.size()<3) { cout<<"NO"; return; }
  else {
      cout<<"YES \n";
      for(auto &j:ans) cout<<j<<" ";
  }

}

int main()
{
 fast_cin();
 #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
    // cout << "Case #" << it+1 << ": ";
     solve();
     cout<<ln;
 }
 return 0;
}
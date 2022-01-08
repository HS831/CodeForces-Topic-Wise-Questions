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
typedef vector<ld> vd64;
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
 

void solve()
{
 ll n,n1,n2;
 cin>>n>>n1>>n2;

 v64 a;
 forn(i,n) {
     ll x; cin>>x;
     a.pb(x);
 }
 sort(a.begin(), a.end(), greater<ll>());
 if(n1<n2) {
    ll l=0, r = n-1;
    float sum1=0;
    while(l<=r && n1>0) {
        sum1 = (sum1 + a[l]);
        l++;
        n1--;
        if(n1<=0) break;
        sum1 = (sum1 + a[r]);
        r--;
        n1--;
    }
    sum1 += (sum1)/n1;
    cout<<sum1;
    float sum2 = 0;
    while(l<=r && n2>0) {
        sum2 = (sum2 + a[l]);
        l++;
        n2--;
        if(n2<=0) break;
        sum2 = (sum2 + a[r]);
        r--;
        n2--;
    }
    sum2 += sum2/n2;
    cout<<sum2;
 }
 else {
    ll l=0, r = n-1;
    ld sum1=0.0;
    while(l<=r && n2) {
        sum1 = (sum1 + a[l])/n2;
        l++;
        n2--;
        if(n2<=0) break;
        sum1 = (sum1 + a[r])/n2;
        r--;
        n2--;
    }
    ld sum2 = 0.0;
    while(l<=r && n1) {
        sum2 = (sum2 + a[l])/n1;
        l++;
        n1--;
        if(n1<=0) break;
        sum2 = (sum2 + a[r])/n1;
        r--;
        n1--;
    }

    cout<<sum1+sum2;
 }

}

int main()
{
 fast_cin();
 #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
 /*ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
     cout << "Case #" << it+1 << ": ";
     solve();
 }*/
 solve();
 return 0;
}
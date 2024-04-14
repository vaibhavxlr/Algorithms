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
 

ll matrix1[100][100], matrix2[100][100];

void solve(int rs, int re, int cs, int ce) {   
 if(rs > re || cs > ce) {
    return;
 }
 cout << matrix1[rs][cs] + matrix2[rs][cs] << " ";
 solve(rs, re, cs + 1, ce);
 if(cs == ce) {
    cout << endl;
    cs = 0;
    solve(rs + 1, re, cs, ce);

 }
}

int main()
{
 fast_cin();
 ll R, C;
 cin >> R >> C;
 for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
        cin >> matrix1[i][j];
    }
 }
 for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
        cin >> matrix2[i][j];
    }
 }
 
 solve(0, R - 1, 0, C - 1);

 return 0;
}
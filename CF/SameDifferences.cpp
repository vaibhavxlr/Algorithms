/**
 * @file SameDifferences.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://codeforces.com/problemset/problem/1520/D
 * @date 2022-10-09
 * 
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
        ll n, count = 0, i = 0; 
        cin >> n;
        unordered_map<ll, ll> mp;

        while(i < n) {
            ll x;
            cin >> x;
            x -= i;
            count += mp[x];
            mp[x]++;
            i++;
        }
 
        cout << count << endl;
}

int main() {
    // cout << "hello";
    ll t;
    cin >> t;

    while(t--) {
        solve();

    }

    // return 0;
}
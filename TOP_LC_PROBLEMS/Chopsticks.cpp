/**
 * @file Chopsticks.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief Problem:- https://www.codechef.com/problems/TACHSTCK
 * @date 2022-06-08
 * 
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ll N, D;
    cin >> N >> D;
    vector<ll> chopsticks;
    ll noOfPairs = 0;

    for(int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        chopsticks.push_back(x);
    }

    sort(chopsticks.begin(), chopsticks.end());

    for(ll i = N - 1; i > 0; i--) {
        if(chopsticks[i] - chopsticks[i - 1] <= D) {
            noOfPairs++;
            i--;
        }
    }

    cout << noOfPairs << endl;
    return 0;
}
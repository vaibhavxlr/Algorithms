/**
 * @file DefenseOfAKingdom.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief Problem:- https://www.codechef.com/submit/WCE0004
 * @date 2022-06-08
 * 
 */

#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
using lli = long long int;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)
main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli T;
    cin >> T;
    while(T--){
        lli w, h, n;
        cin >> w >> h >> n;
        vector<lli> row, col;
        row.push_back(0);
        col.push_back(0);
        
        for(lli i = 1; i <= n; i++) {
            lli x, y;
            cin >> x >> y;
            row.push_back(x);
            col.push_back(y);
        }
        
        sort(row.begin(), row.end());
        sort(col.begin(), col.end());
        lli maxX = INT_MIN;
        lli maxY = INT_MIN;
        
        for(lli i = 1; i <= n; i++) {
            maxX = max(maxX, row[i] - row[i - 1] - 1);
            maxY = max(maxY, col[i] - col[i - 1] - 1);
        }

        maxX = max(maxX, w - row[n]);
        maxY = max(maxY, h - col[n]);
        
        cout << maxX * maxY << endl;
    }
  
    
}
    
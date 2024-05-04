#include <bits/stdc++.h>
using namespace std;

int stk[2][100001];
int dp[2][100001];

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
    
   int test;
   cin >> test;
   while(test--){
       int n;
       cin >> n;
       for(int i=0; i<2; i++){
           fill(dp[i],dp[i]+n,0);
           for(int j=0; j<n; j++){
            cin >> stk[i][j];
           }
       }
       dp[0][0] = stk[0][0];
       dp[1][0] = stk[1][0];
       dp[0][1] = dp[1][0] + stk[0][1];
       dp[1][1] = dp[0][0] + stk[1][1];
       
       for(int i=2; i<n; i++){
           dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + stk[0][i];
           dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + stk[1][i];
       }
       
       cout << max(dp[0][n-1],dp[1][n-1]) << '\n';
       
   }
}
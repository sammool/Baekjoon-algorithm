#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
   int arr[501][501];
   int dp[501][501];
   
   int n;
   cin >> n;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=i; j++){
           cin >> arr[i][j];
       }
   }
   
   for(int i=1; i<=n; i++){
       for(int j=1; j<=i; j++){
          if(j == 1){
              dp[i][j] = dp[i-1][j] + arr[i][j];
          }
          else if(j==i){
              dp[i][j] = dp[i-1][j-1] + arr[i][j];
          }
          else{
              dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
          }
       }
   }
   
   cout << *max_element(dp[n], dp[n]+n+1);
}
#include <bits/stdc++.h>
using namespace std;

long long dp[101];

int main(){
    int t_case;
    cin >> t_case;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for(int i=6; i<=100; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
    for(int i=0; i<t_case; i++){
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }
}
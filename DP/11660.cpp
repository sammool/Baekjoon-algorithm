#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);   

    int n,m;
    int dp[1025][1025]; 
    
    cin >> n >> m;

    int value;

    for(int i =1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> value;
            dp[i][j] = value + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
        }
    }

    for(int i=0 ;i<m; i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]<< '\n';
}

}


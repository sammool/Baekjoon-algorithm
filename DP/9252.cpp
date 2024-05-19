#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(){
    string str1;
    string str2;
    cin >> str1 >> str2;

    for(int i=1; i<=str1.length(); i++){
        for(int j=0; j<=str2.length(); j++){
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    //dp배열 역추적 해서 찾기
    int i = str1.length();
    int j = str2.length();
    string str = "";
    while(i>=0 && j>=0){
        //대각으로 가는 경우 추가 O
        if(dp[i][j] > dp[i-1][j-1] && dp[i-1][j-1] == dp[i-1][j] 
            && dp[i-1][j-1] == dp[i][j-1]){
            str += str1[i-1];
            i--;
            j--;
        }
        //대각으로 가는 경우2 but 추가 X
        else if(dp[i][j] == dp[i-1][j-1] && dp[i][j] == dp[i-1][j] 
            && dp[i][j] == dp[i][j-1]){
            i--;
            j--;
        }
        //위로 가는 경우
        else if(dp[i][j] == dp[i-1][j]){
                i--;
            }
        else 
            j--;
    }

    reverse(str.begin(), str.end());
    cout << dp[str1.length()][str2.length()] << '\n';
    cout << str;
}
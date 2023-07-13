#include <iostream>
#include <string>
using namespace std;
int dp[1001][1001];

int main()
{
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    for(int i=1; i<=str1.length(); i++)
    {
        for(int j=1; j<=str2.length(); j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;   //대각선을 이용하는 것이 중요!!
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        
    }
    cout << dp[str1.length()][str2.length()];
}
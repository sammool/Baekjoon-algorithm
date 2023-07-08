#include <iostream>
using namespace std;

int dp[15];

int main()
{
    int Case;
    cin >> Case;

    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=0; i<Case; i++)
    {
        int n;
        cin >> n;
        for(int j=4; j<=n; j++)
        {
            dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
        }
        cout << dp[n] << '\n';
    }
}
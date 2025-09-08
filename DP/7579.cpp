#include <bits/stdc++.h>
using namespace std;
int dp[101][10001];
int memory[101];
int cost[101];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <=n; i++)
        cin >>memory[i];
    for(int i = 1; i <= n; i++)
        cin >>cost[i];

    fill(dp[0], dp[0] + 10001, 0);
    for(int i = 1; i <= n; i++)
    {
        for(int j=0; j<=10000; j++)
        {
            if(j-cost[i]<0)
            {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i]);
        }
    }

    for (int j=0; j<=10000; j++)
    {
        for (int i=1; i<=n; i++)
        {
            if (dp[i][j] >= m)
            {
                cout << j;
                return 0;
            }
        }
    }
}
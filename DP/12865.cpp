#include <iostream>
using namespace std;

int dp[101][100001];
int weight[100001];
int value[1001];

int main()
{
    int n,k;
    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin >> weight[i] >> value[i];

    /*for(int i=0; i<n; i++)
        dp[i][0]=0;*/ 

    for(int i=1; i<=n; i++)
    {
        for(int w=1; w<=k; w++)
        {
            if(weight[i] > w)
             dp[i][w]=dp[i-1][w];
            
            else if(weight[i] <= w)
                dp[i][w]=max(dp[i-1][w], value[i]+dp[i-1][w-weight[i]]);
        }
    }
    cout << dp[n][k];
    
}
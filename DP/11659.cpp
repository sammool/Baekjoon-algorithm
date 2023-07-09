#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int dp[100001];
    int arr[100001];

    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        {
            cin >> arr[i];
            if(i==1)
            {
                dp[i]=arr[i];
                continue;
            }
            dp[i]=dp[i-1]+arr[i];
        }
    for(int l=0; l<m; l++)
    {
        int i,j;
        cin >> i >> j;
        cout << dp[j]-dp[i-1]<<'\n';
    }
}
// Prefix sum
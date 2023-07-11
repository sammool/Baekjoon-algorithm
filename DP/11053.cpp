#include <iostream>
using namespace std;

int dp[1001];
int arr[1001];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        dp[i]=1;
    }
    int result=1;

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[j]<arr[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
        if(result<dp[i])
            result=dp[i];
    }
    cout << result;
}
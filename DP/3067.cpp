#include <iostream>
using namespace std;

int coin[21];
int dp[10001];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t_case;
    cin >> t_case;
    for(int q=0; q<t_case; q++)
    {
        int n;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> coin[i];
        }

        int goal;
        cin >> goal;
        
        fill(dp,dp+10001,0);
        dp[0]=1;
        
        for(int j=0; j<n; j++)
        {
            for(int i=1; i<=goal; i++)
            {
                if(i-coin[j]<0)
                    continue;
                dp[i]+=dp[i-coin[j]];   
            }
        }
        cout << dp[goal] << '\n';
    }

}
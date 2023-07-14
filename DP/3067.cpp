#include <iostream>
using namespace std;

int coin[21];
int dp[10001];

int main()
{
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

        dp[0]=0;
        for(int i=1; i<=goal; i++)
        {
            
        }
    }
}
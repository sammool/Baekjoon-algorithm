#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];
int money[3];


int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            for(int j=0; j<3; j++)
            {
                cin >> money[j];
                dp[0][j]=money[j];
            }
        }

        else
        {
            for(int j=0; j<3; j++)
                cin >> money[j];

            for(int k=1; k<n; k++)
            {    
                dp[i][0]=min(dp[i-1][1]+money[0],dp[i-1][2]+money[0]);
                dp[i][1]=min(dp[i-1][0]+money[1],dp[i-1][2]+money[1]);
                dp[i][2]=min(dp[i-1][0]+money[2],dp[i-1][1]+money[2]);
            }
        }
    }
    
    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
 
  
}
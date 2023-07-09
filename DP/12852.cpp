#include <iostream>
using namespace std;
//기억할것 pro는 경로 복원용 테이블 : pro[i]의 값은 값이 어디로부터 왔는지를 알려줌 
int main()
{
    int dp[1000001];
    int pro[1000001];
    int x;
    cin >> x;

    dp[1]=0;
    pro[1]=0;
    

    for(int i=2; i<=x; i++)
    {
        dp[i]=dp[i-1]+1;
        pro[i]=i-1;

        if(i%2==0)
        {
            if(dp[i/2]+1 < dp[i])
            {
                dp[i]=dp[i/2]+1;
                pro[i]=i/2;
            }

        }
            
        if(i%3==0)
       {
            if(dp[i/3]+1 < dp[i])
            {
                dp[i]=dp[i/3]+1;
                pro[i]=i/3;
            }

        }
    }
    int cur=x;
    cout <<dp[x]<<'\n';
    while(1)
    {
        cout << cur <<" ";
        if(cur==1)
            break;
        cur=pro[cur];

    }
}
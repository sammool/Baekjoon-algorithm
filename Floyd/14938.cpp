#include <bits/stdc++.h>
using namespace std;

int cost[102][102]; // 길이
int item[102];
int infi = 0xffff;

int main()
{
    int n,m,r;
    cin >> n >> m >> r;

    for(int i=1; i<=n; i++)
        cin >> item[i];
    
    for(int i=1; i<=n; i++)
        fill(cost[i],cost[i]+n+1,infi);
    
    for(int i=1; i<=n; i++)
        cost[i][i] = 0;
    

    int a,b,len;
    for(int i=1; i<=r; i++)
    {
        cin >> a >> b >> len;
        cost[a][b] = min(cost[a][b], len);
        cost[b][a] = min(cost[b][a], len);
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }
    
    int tmp = 0;
    for(int i=1; i<=n; i++)
    {
        int res = 0;
       
        for(int j=1; j<=n; j++)
        {
            if(cost[i][j] <= m)
                res+=item[j];
        }
        tmp = max(res,tmp);
    }

    cout << tmp;
}
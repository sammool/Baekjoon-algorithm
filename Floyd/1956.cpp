#include <bits/stdc++.h>
using namespace std;

int cost[402][402];
int infi = 0xffffff;

int main()
{
    int v,e;
    cin >> v >> e;

    for(int i=1; i<=v; i++)
    {
        fill(cost[i],cost[i]+v+1, infi);
        cost[i][i] = 0;
    }

    int a,b,len;
    for(int i=1; i<=e; i++)
    {
        cin >> a >> b >> len;
        cost[a][b] = len; //(a,b) 쌍이 같은 도로가 여러 번 주어지지 않는다
    }

    for(int k=1; k<=v; k++)
    {
        for(int i=1; i<=v; i++)
        {
            for(int j=1; j<=v; j++)
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
        }
    }

    int tmp = infi;
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(i == j)
                continue;
            tmp = min(tmp, cost[i][j]+cost[j][i]);
        }
    }
    if(tmp == infi)
        cout << -1;
    else
        cout << tmp;

}
#include <bits/stdc++.h>
using namespace std;

int cost[102][102];
const int infinite = 0xffffff;


int main()
{
    int n,m;
    cin >> n;
    cin >> m;

    for(int i=1; i<=n; i++)
        fill(cost[i],cost[i]+n+1,infinite);

    int x,y,v;
    for(int i=0; i<m; i++)
    {
        cin >> x >> y >> v;
        cost[x][y] = min(cost[x][y],v);
    }

    for(int i=1; i<=n; i++)
        cost[i][i] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(cost[i][j] == infinite)
                cout << "0 ";
            else
                cout << cost[i][j] << " ";
        }
        cout << '\n';
    }

}
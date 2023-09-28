#include <bits/stdc++.h>
using namespace std;

int cost[102][102];
int nxt[102][102];
int infi = 0xffffff;
int n,m;


int main()
{
    
  
    cin >> n;
    cin >> m;
    
    for(int i=1; i<=n; i++)
        fill(cost[i],cost[i]+n+1,infi);
    
    int a,b,value;
    for(int i=1; i<=m; i++)
    {
        cin >> a >> b >> value;
        cost[a][b] = min(cost[a][b], value);
        nxt[a][b] = b;
    }
    for(int i=1; i<=n; i++)
        cost[i][i] = 0;

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(cost[i][j] > cost[i][k]+cost[k][j] )
                {
                    cost[i][j] = cost[i][k]+cost[k][j];
                    nxt[i][j] = nxt[i][k]; // j
                }
            }
        }
    }

    //최단경로
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(cost[i][j] == infi)
                cout << 0 << " ";
            else
                cout << cost[i][j] << " ";
        }
        cout << '\n';
    }
    

    //경로복원
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(cost[i][j] == 0 || cost[i][j] == infi)
            {
                cout << 0 <<'\n';
                continue;
            }

            vector <int> path;
            int st = i;
            while(st != j)
            {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);

            cout << path.size() << " ";
            for(int element: path)
                cout << element <<  " ";

            cout << '\n';

        }
    }
}

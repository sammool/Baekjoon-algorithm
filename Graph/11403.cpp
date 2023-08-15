#include <iostream>
#include <queue>
using namespace std;

int adj [101][101];
bool res [101][101];
queue <int> q;

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int x;
            cin >> x;
            if(x==1)
                adj[i][j] = j;
        }
    }

    for(int i=1; i<=n; i++)
    {
        bool vis[101];
        fill(vis, vis+101, 0);

        q.push(i);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int nx=1; nx<=n; nx++)
            {
                if(!adj[cur][nx] || vis[nx])
                    continue;
                q.push(nx);
                vis[nx] = true;                
            }
        }  
        for(int j=1; j<=n; j++)
        {
            if(vis[j])
                res[i][j] = true;
        }

    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }

}
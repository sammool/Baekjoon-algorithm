#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector<int> adj[1001];
    bool vis[1001];

    int n,m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x); 
    }
    
    queue <int> q;
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        if(vis[i])
            continue;
            
        q.push(i);
        vis[i] = true;
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            for(int nxt : adj[cur])
            {
                if(vis[nxt])
                    continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
        cnt++;
    }
}
#include <bits/stdc++.h>
using namespace std;
vector <int> adj[501];
int dist[501];

void bfs()
{
    queue <int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int nxt : adj[cur])
        {
            if(dist[nxt])
                continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs();
    int cnt = 0;
    for(int i = 2; i<=n; i++)
    {
        if(dist[i] > 0 && dist[i] <3)
            cnt++;
    }
    cout << cnt;
}
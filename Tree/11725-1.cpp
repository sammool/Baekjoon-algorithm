#include <bits/stdc++.h>
using namespace std;

//bfs풀이

int main()
{
    vector <int> adj[100002];
    int par[100002];

    int n;
    cin >> n;
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue <int> q;
    q.push(1);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int nxt : adj[cur])
        {
            if(par[nxt])
                continue;
            q.push(nxt);
            par[nxt] = cur;
        }
    }

    for(int i=2; i<=n; i++)
    {
        cout << par[i] << '\n';
    }
}
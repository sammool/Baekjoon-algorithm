//재귀 DFS 풀이

#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100002];
int par[100002];

void dfs(int top)
{
    int cur = top;
   for(int nxt : adj[top])
   {
        if(par[nxt])
            continue;
        par[nxt] = cur;
        dfs(nxt);
   }
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for(int i=2; i<=n; i++)
        cout << par[i] << '\n';
}
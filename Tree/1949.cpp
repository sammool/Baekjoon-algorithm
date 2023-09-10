#include <bits/stdc++.h>
using namespace std;

vector <int> adj[10005];
int citizen[10005];
int dp[10005][2];
bool vis[10005];

void dfs(int cur)
{
    vis[cur] = true;

    dp[cur][0] = 0;
    dp[cur][1] = citizen[cur];
    
    for(int nxt: adj[cur])
    {
        if(vis[nxt])
            continue;
        dfs(nxt);
        dp[cur][0] += max(dp[nxt][0],dp[nxt][1]);
        dp[cur][1] += dp[nxt][0];
    }
}


int main()
{
    int n;
    int x,y;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> citizen[i];
    for(int i=1; i<n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    cout << max(dp[1][0], dp[1][1]);

}
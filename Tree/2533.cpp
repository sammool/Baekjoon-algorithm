#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1000002]; 
bool vis[1000002];
int dp[1000002][2];

void dfs(int cur) 
{
    vis[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    
    for(int nxt: adj[cur])
    {
        if(vis[nxt])
            continue;
       
        
        dfs(nxt);
        dp[cur][0] += dp[nxt][1];
        dp[cur][1] += min(dp[nxt][0],dp[nxt][1]);
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
    cout << min(dp[1][0],dp[1][1]);


}

#include <bits/stdc++.h>
using namespace std;
vector <int> adj[100002];
bool vis[100002];
int dist [100002];


void dfs(int cur, int par)
{
    vis[cur] = true;
    for(int nxt: adj[cur])
    {
        if(vis[nxt])
            continue;
        dfs(nxt,cur);
        dist[cur] += dist[nxt];
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n,root, query;
	cin >> n >> root >> query;
	for(int i=1; i<n; i++)
	{
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	 fill(dist, dist+100002, 1);
	 dfs(root,-1);
	
	for(int i=0; i< query; i++)
	{
		int x;
		cin >> x;
		  
        cout << dist[x] << '\n';       
	}
}
#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> adj[1002];
bool vis[1002];

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n-1; i++)
	{
		int x,y,dis;
		cin >> x >> y >> dis;
		adj[x].push_back({y,dis});
		adj[y].push_back({x,dis});
	}
	
	for(int i=0; i<m; i++)
	{
		int x,y;
		cin >> x >> y;
		
		queue <pair<int,int>> q;
		q.push({x,0});

        fill(vis,vis+1002,0);
		vis[x] = true;
		while(!q.empty())
		{
			auto cur = q.front();
			q.pop();
			
			if(cur.first == y)
			{
				cout << cur.second << '\n';
				break;
			}
				
			for(auto nxt : adj[cur.first])
			{
				if(vis[nxt.first])
					continue;
				vis[nxt.first] = true;
				q.push({nxt.first, cur.second + nxt.second});
				
			}
		}
	}
}
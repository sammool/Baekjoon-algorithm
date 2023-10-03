#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> adj[20002];
priority_queue <pair<int,int>, vector<pair<int,int>>, 
                greater <pair<int,int>> > pq;
int dis[20002];
int inf = 0xffff;

int main()
{
    int n,m,start;
    cin >> n >> m;
    cin >> start;
    
    int x,y,cost;
    for(int i=1; i<=m; i++)
    {
        cin >> x >> y >> cost;
        adj[x].push_back({y,cost});
    }

    fill(dis,dis+n+1, inf);
    dis[start] = 0;
    pq.push({0,start});

    while(true)
    {
        int idx = pq.top().second;
        for(auto nxt : adj[idx])
        {
            if()
        }
    }


}
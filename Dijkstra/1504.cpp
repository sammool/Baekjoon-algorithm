#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;


vector <pair<int,int>> adj[802];
int dist[802];
const int INF = 1e9;

int n,m;
int a,b,cost;

long long dijkstra(int st, int en)
{
    priority_queue <pair<int,int>, vector<pair<int,int>>, 
                         greater<pair<int,int>> > pq;
    fill(dist,dist+n+1,INF);
    dist[st] = 0;
    pq.push({0,st});
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.Y]!=cur.X)
            continue;
        for(auto nxt : adj[cur.Y])
        {
            if(dist[nxt.Y] <= dist[cur.Y] + nxt.X)
                continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }
    return dist[en];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
  
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> cost;
        adj[a].push_back({cost,b});
        adj[b].push_back({cost,a});
    }

    int x,y;
    cin >> x >> y;

    long long res = INF;
   
    long long case1,case2;
    case1 = dijkstra(1,x) + dijkstra(x,y) + dijkstra(y,n);
    case2 = dijkstra(1,y) + dijkstra(y,x) + dijkstra(x,n);
    if(case1 <= case2)
        {res = min(res,case1);}
    else
        {res = min(res,case2);}

    if(res >= INF)
        res = -1;
    cout << res;
}
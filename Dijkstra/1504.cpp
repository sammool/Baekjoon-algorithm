#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> adj[802];
int dist[802];
const int INF = 800001;

int main()
{
    int n,m;
    cin >> n >> m;
    
    int a,b,cost;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> cost;
        adj[a].push_back({cost,b});
        adj[b].push_back({cost,a});
    }

    for(int i=1; i<=n; i++)
    {
        priority_queue <pair<int,int>, vector<pair<int,int>>, 
                         greater<pair<int,int>> > pq;
        fill(dist,dist+n+1,INF);
        dist[i] = 0;
    }
}
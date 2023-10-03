#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> adj[20002];
priority_queue <pair<int,int>, vector<pair<int,int>>, 
                greater <pair<int,int>> > pq;
int dis[20002];
int inf = 0xffffff;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

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

    while(!pq.empty())
    {
        auto idx = pq.top();
        pq.pop();
        
        if(dis[idx.second] != idx.first)  //최솟값으로 갱신이 여러번 됐을때 이전에 갱신된 값이 들어갈 수 있기 때문
            continue;
        
        for(auto nxt : adj[idx.second])
        {

            if(dis[nxt.first] > dis[idx.second] + nxt.second)
            {
                dis[nxt.first] = dis[idx.second] + nxt.second;
                pq.push({dis[nxt.first],nxt.first});
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(dis[i] == inf)
            cout << "INF" << '\n';
        else
            cout << dis[i] << '\n';
    }

}
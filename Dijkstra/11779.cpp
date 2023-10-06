#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> adj[1002];

int dist[1002];
int pre[1002];
const int infi = 200000000; // INF를 잘 설정하는 것이 중요! 정점수 * 최대정점비용 +1

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n;
    cin >> m;

    int a,b,cost;
    for(int i=1; i<=m; i++)
    {
        cin >> a >> b >> cost;
        adj[a].push_back({b,cost});
    }

    int start, end;
    cin >> start >> end;
    fill(dist,dist+n+1,infi);
    dist[start] = 0;
    
    priority_queue <pair<int,int>, vector<pair<int,int>>,
                greater<pair<int,int>> > pq;

    pq.push({0,start});
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(dist[cur.second] != cur.first)
            continue;

        for(auto nxt: adj[cur.second])
        {
            if(dist[nxt.first] <= dist[cur.second] + nxt.second)
                continue;
            
            dist[nxt.first] = dist[cur.second] + nxt.second;
            pre[nxt.first] = cur.second;
            pq.push({dist[nxt.first], nxt.first});
        
        }
    }

    cout << dist[end] << '\n';

    vector <int> v;

    int x = end;
    while(x!=start)
    {
        v.push_back(x);
        x = pre[x];
    }
    v.push_back(x);

    cout << v.size() << '\n';
   for(int i = v.size()-1; i>=0; i--)
        cout << v[i] << " ";


}
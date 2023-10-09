#include <bits/stdc++.h>
#define X first
#define Y second
/*면접장에서 도시까지의 최단경로로 역발상 하는 문재 
도시의 수가 10^5, 도로의 길이가 10^5이기 때문에
int 범위를 넘을 가능성이 있어 거리 계산 시에 long long 타입을 사용*/
using namespace std;

typedef long long ll;

vector <pair<ll,int>> adj[100002];
priority_queue <pair<ll,int>, vector<pair<ll,int>>, 
                         greater<pair<ll,int>> > pq; 
const ll INF =1e18;
ll dist[100002];
int n,m,k;
int a,b,cost;

void dijkstra()
{
   while(!pq.empty())
   {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.Y] != cur.X)
            continue;
        for(auto nxt : adj[cur.Y])
        {
            if(dist[nxt.Y] <= dist[cur.Y] + nxt.X)
                continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y],nxt.Y});
        }
   }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> cost;
        adj[b].push_back({cost,a});
    }

    fill(dist,dist+n+1,INF);

    int meet;
    for(int i=1; i<=k; i++)
    {
        cin >> meet;
        dist[meet] = 0;
        pq.push({0,meet});
    }

    dijkstra();
    int idx = max_element(dist+1,dist+n+1) - dist;
    ll value = dist[idx];
    cout << idx <<'\n' << value;

}












/*각 도시에서 면접장 까지의 거리를 계산한 풀이 
시간복잡도는 O(VElgE)가 되며, V와 E가 10^5 단위기 때문에
제한 시간 내로 풀리지 않음.*/

// using namespace std;

// vector <pair<int,int>> adj[100002];
// int dist[100002];
// int place[100002];

// const int INF = 1e9;
// int n,m,k;
// int a,b,cost;


// int dijkstra(int st, int en)
// {
//     fill(dist,dist+n+1,INF);
//     dist[st] = 0;
//     priority_queue < pair<int,int> ,vector<pair<int,int>>, 
//                     greater<pair<int,int>> > pq;

//     pq.push({0,st});
//     while(!pq.empty())
//     {
//         auto cur = pq.top();
//         pq.pop();
//         if(dist[cur.Y]!=cur.X)
//             continue;
//         for(auto nxt: adj[cur.Y])
//         {
//             if(dist[nxt.Y] <= dist[cur.Y]+nxt.X)
//                 continue;
//             dist[nxt.Y] = dist[cur.Y] + nxt.X;
//             pq.push({dist[nxt.Y],nxt.Y});
//         }
//     }
//     return dist[en];
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n >> m >> k;
    
//     for(int i=1; i<=m; i++)
//     {
//         cin >> a >> b >> cost;
//         adj[a].push_back({cost,b});
//     }
//     for(int i=1; i<=k; i++)
//         cin >> place[i];

//     int longest = 0;
//     int tmp;
//     for(int i=1; i<=n; i++)
//     {
//         int distance = INF;
       
//         for(int j=1; j<=k; j++)
//         {
//             distance = min(distance, dijkstra(i,place[j]));
//         }
        
//         if(longest < distance)
//         {
//             longest = distance;
//             tmp = i;
//         }
//     }

//     cout << tmp << '\n';
//     cout << longest;
    
// }
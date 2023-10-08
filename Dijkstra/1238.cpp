#include <bits/stdc++.h>
#define X first 
#define Y second 
using namespace std;

vector <pair <int,int>> adj[1002];

int dist[1002];
const int INF = 200000;

int n,m,x;
int a,b;

int dijkstra(int st, int en)
{
    priority_queue <pair<int,int>, vector <pair<int,int>>, 
                greater<pair<int,int>>> pq;
    fill(dist,dist+n+1,INF);
    dist[st] = 0;
    pq.push({0,st});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.Y]!=cur.X)
            continue;
        for(auto nxt: adj[cur.Y])
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
   
    cin >> n >> m >> x;

    int time;
    for(int i=1; i<=m; i++)
    {
        cin >> a >> b >> time;
        adj[a].push_back({time,b});
    }

    int res = 0;
    for(int i=1; i<=n; i++)
    {
        res = max(res,dijkstra(i,x)+dijkstra(x,i));
    }
    cout <<  res;
}

// //플로이드 풀이
// #include <bits/stdc++.h>
// #define X first 
// #define Y second 
// using namespace std;
// int INF =200000;
// int dist[1002][1002];

// int main()
// {
//     int n,m,x;
//     cin >> n >> m >> x;
    
//     int a,b,time;

//     for(int i=1; i<=n; i++)
//     {
//         fill(dist[i],dist[i]+n+1,INF);
//         dist[i][i] = 0;
//     }

//     for(int i=1; i<=m; i++)
//     {
//         cin >> a >> b >> time;
//         dist[a][b] = time;
//     }

//     for(int k=1; k<=n; k++)
//     {
//         for(int i=1; i<=n; i++)
//         {
//             for(int j=1; j<=n; j++)
//                 dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
//         }
//     }

//     priority_queue <int> pq;
//     for(int i=1; i<=n; i++)
//         pq.push(dist[i][x] + dist[x][i]);
//     while(true)
//     {
//         if(pq.top() == INF)
//         {
//             pq.pop();
//             continue;
//         }
//         cout << pq.top();
//         return 0;
//     }
// }
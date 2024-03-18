#include <bits/stdc++.h>
using namespace std;

int n,m;
long long cost[1001];
long long INF = 1e10 +100;

vector<pair<int,int>> adj[100001];
priority_queue <pair<int,int>, vector<pair<int,int>>,
                greater<pair<int,int>> > pq;

int main(){
    //input
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
    }

    int start, end;
    cin >> start >> end;

    //Dijkstra
    fill(cost,cost+n+1,INF);
    cost[start] = 0;

    //(비용, 정점)
    pq.push({0,start});

    while(!pq.empty()){
        auto idx = pq.top();
        pq.pop();
        if(cost[idx.second] != idx.first)
            continue;

        for(auto nxt : adj[idx.second]){
            if(cost[nxt.first] > cost[idx.second] + nxt.second ){
                cost[nxt.first] = cost[idx.second] + nxt.second;
                pq.push({cost[nxt.first], nxt.first});
            }
        }
    }
    cout << cost[end];

}
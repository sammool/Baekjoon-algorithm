#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> adj[7];
int dis[7];
bool End[7];
int infi = 0xffff;

priority_queue <pair<int,int>, vector<pair<int,int>>, greater <pair<int,int>> > pq;

void Dijkstra()
{
    pq.push({0,1});
    while(1)
    {
        int idx = pq.top().second;
        for(auto nxt: adj[idx])
        {
            if(dis[nxt.second] > dis[idx]+nxt.first)
            {
                dis[nxt.second] = dis[idx] + nxt.first;
                pq.push({dis[idx] + nxt.first, nxt.second});
            }
        }
    }
}



int main()
{
   
}
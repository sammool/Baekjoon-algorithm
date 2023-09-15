#include <bits/stdc++.h>
using namespace std;
//           정점, 가중치
vector <pair<int,int>> adj[10002];
priority_queue <tuple<int,int,int>, 
                vector<tuple<int,int,int>>,
                greater<tuple<int,int,int>> > pq;

bool chk[10002];

int main()
{
    int v,e;
    cin >> v >> e;
    int a,b,value;
    for(int i=1; i<=e; i++)
    {
        cin >> a >> b >> value;
        adj[a].push_back({value,b});
        adj[b].push_back({value,a});
    }

    chk[1] = 1;
    for(auto nxt : adj[1])
    {
        pq.push({nxt.first,1,nxt.second});
    }
    int cnt=0;
    int value_sum=0;
    while(cnt <v-1)   //v-1개의 간선이 포함되도록
    {
        int a,b,cost;
        tie(cost,a,b) = pq.top();
        pq.pop();
        if(chk[b])
            continue;
        chk[b]=1;
        cnt++;
        value_sum+=cost;

        for(auto nxt: adj[b])
        {
            if(!chk[nxt.second])
                pq.push({nxt.first,b,nxt.second});
        }
    }
    cout << value_sum;
}
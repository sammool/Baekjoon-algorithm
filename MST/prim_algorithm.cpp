#include <bits/stdc++.h>
using namespace std;

int main()
{

    int v,e;
    //          비용,정점번호
    vector <pair <int,int>> adj[10005];

    //정점이 최소 신장 트리에 속해있는가?
    bool chk[10005]; 
    int cnt=0; //선택된 간선의 수

    priority_queue <tuple<int,int,int>, 
                    vector<tuple<int,int,int>>, 
                    greater<tuple<int,int,int>> > pq;

    chk[1] = 1;
    for(auto nxt: adj[1])
    {
        pq.push({nxt.first, 1, nxt.second});
    }

    while(cnt < v-1)
    {
        int cost,a,b;
        tie(cost,a,b) = pq.top();
        pq.pop();
        if(chk[b])
            continue;
        cout << a << " " << b << " " << '\n';
        chk[b]=1;
        cnt++;

        for(auto nxt: adj[b])
        {
            if(!chk[nxt.second])
                pq.push({nxt.first, b, nxt.second});
        }
    }



}
#include <bits/stdc++.h>
using namespace std;

vector <int> adj[32002];
int indegree[32002];

int main()
{
    int n,m;
    cin >> n >> m;

    int x,y;
    for(int i=0; i<m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    priority_queue <int, vector<int>, greater<int>> pq; //오름차순
    for(int i=1; i<=n; i++)
    {
        if(!indegree[i])
            pq.push(i);
    } 
    while(!pq.empty())
    {
        int cur = pq.top();
        cout << cur << " ";
        pq.pop();
        for(int nxt : adj[cur])
        {
            indegree[nxt]--;
            if(!indegree[nxt])
                pq.push(nxt);
        }

    }

}
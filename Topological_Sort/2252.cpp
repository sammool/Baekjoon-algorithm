#include <bits/stdc++.h>
using namespace std;

vector <int> adj[32001];
vector <int> res;
int indegree[32001];

void topological_sort(int n)
{
    queue <int> q;
    for(int i=1; i<=n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int cur = q.front();
        res.push_back(cur);
        q.pop();
        for(int nxt:adj[cur])
        {
            indegree[nxt]--;
            
            if(!indegree[nxt])
                q.push(nxt);
        }
    }

    for(int ele : res)
        cout << ele << " ";
}    

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    
    int x,y;
    for(int i=0; i<m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    topological_sort(n);
}
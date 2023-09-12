#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1002];
vector <int> res;
int indegree[1002];

int main()
{
    int singer, pd;
    cin >> singer >> pd;
    
    int n;
    int prev,next;
    for(int i=1; i<=pd; i++)
    {
        cin >> n;
        cin >> prev;
        for(int j=1; j<n; j++)
        {
            cin >> next;
            adj[prev].push_back(next);
            indegree[next]++;
            swap(prev,next);
        }
    }

    queue <int> q;
    for(int i=1; i<=singer; i++)
    {
        if(!indegree[i])
            q.push(i);
    }

    while(!q.empty())
    {
        int cur = q.front();
        res.push_back(cur);
        q.pop();
        for(int nxt: adj[cur])
        {
            indegree[nxt]--;
            if(!indegree[nxt])
                q.push(nxt);
        }
    }
    if(res.size() < singer)
        cout << 0;
    else
    {
        for(auto ele : res)
            cout << ele << '\n';
    }
}
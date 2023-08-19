#include <bits/stdc++.h>
using namespace std;

vector <int> party[51];
vector <int> adj[51];
bool t_or_f[51];
int main()
{
    int n,m;
    cin >> n >> m;
    int truth;
    cin >> truth;
    
    for(int i=0; i<truth; i++)
    {
        int x;
        cin >> x;
        t_or_f[x] = true;
    }
    
    for(int i=1; i<=m; i++)
    {
        int x;
        cin >> x;
        int prev, nxt;
        cin >> prev;
        party[i].push_back(prev);
        for(int j=1; j<x; j++)
        {
           cin >> nxt;
           party[i].push_back(nxt);
           adj[prev].push_back(nxt);
           adj[nxt].push_back(prev);
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        queue <int> q;
        if(t_or_f[i])
            q.push(i);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int nxt : adj[cur])
            {
                if(t_or_f[nxt])
                    continue;
                q.push(nxt);
                t_or_f[nxt] = true;
            }      

        }
    }
    int cnt = m;
    for(int i=1; i<=m ;i++)
    {
      
        for(int res : party[i])
        {
            if(t_or_f[res])
            {
                cnt--;
                break;
            }
        }
    }

    cout << cnt;

}
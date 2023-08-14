#include <bits/stdc++.h>
using namespace std;

vector <int> v[1001];
bool vis[1001];
int n,m,ver;

void bfs()
{
    queue <int> q;
    q.push(ver);
    vis[ver] = true;
   
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        
        for(int nxt: v[cur])
        {
            if(vis[nxt])
                continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }

}

void dfs(int value)
{
    vis[value] = true;
    int cur = value;
    cout << cur << " ";
    for(int nxt : v[cur])
    {
        if(vis[nxt])
            continue;
        vis[nxt] = true;
        dfs(nxt);
    }
} // 재귀로 구현

void dfs2(int value)
{
    stack <int> stk;
    stk.push(value);
    vis[value] = true;
    while(!stk.empty())
    {
        int cur = stk.top();
        stk.pop();
        cout << cur << " ";
        for(int nxt : v[cur])
        {
            if(vis[nxt])
                continue;
            stk.push(nxt);
            vis[nxt] = true;
        }
    }

}

int main()
{
    cin >> n >> m >> ver;
    for(int i=0; i<m; i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    for(int i=1; i<=n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    dfs2(ver);
    cout << '\n';
    fill(vis, vis+1001, 0);
    bfs();
   
}
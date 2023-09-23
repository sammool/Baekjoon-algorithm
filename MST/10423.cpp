#include <bits/stdc++.h>
using namespace std;

//가상의 노드를 만들면 쉽게 해결

vector <tuple<int,int,int>> adj;

int parent[1002];

int find(int x)
{
    if(x==parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

bool Union(int x, int y)
{
    x = find(x);
    y = find(y);

    if(x==y)
        return false;
    if(x<y)
        parent[y]=x;
    else
        parent[x]=y;
    return true;
}


int main()
{
    int n,m,dev;
    cin >> n >> m >> dev;

    for(int i=0; i<=n; i++)
        parent[i] = i;
    
    int x;
    for(int i=1; i<=dev ; i++)
    {
        cin >> x;
        Union(0,x);
    }

    int u,v,value;
    for(int i=1; i<=m; i++)
    {
        cin >> u >> v >> value;
        adj.push_back({value,u,v});
    }

    sort(adj.begin(),adj.end());

    int cnt = 0;
    int sum=0;
    for(auto nxt:adj)
    {
        if(cnt == n-dev)
            break;

        int a,b,cost;
        tie(cost,a,b) = nxt;
        if(Union(a,b))
        {
            sum+=cost;
            cnt++;
        }   
    }

    cout << sum;

}
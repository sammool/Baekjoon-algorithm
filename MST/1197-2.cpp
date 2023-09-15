#include <bits/stdc++.h>
using namespace std;

vector <tuple<int,int,int>> adj;

int v,e;
int parent[10002];

int find(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

bool Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x==y)
        return true;
    if(x < y)
        {parent[y] = x;}
    else
        {parent[x] = y;}
    return false;

}

int main()
{
    cin >> v >> e;
    for(int i=1; i<=v; i++)
        parent[i] = i;
   
    int a,b,value;
    for(int i=1; i<=e; i++)
    {
        cin >> a >> b >> value;
        adj.push_back({value,a,b});
    }
   
    sort(adj.begin(),adj.end());

    int sum=0;
    int cnt=0;
   
    for(auto nxt : adj)
    {
        if(cnt == v-1)
            break;
        int a,b,cost;
        tie(cost,a,b) = nxt;
        if(Union(a,b))
            continue;
        sum+=cost;
    }

    cout << sum;
    
}
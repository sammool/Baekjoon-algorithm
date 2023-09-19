#include <bits/stdc++.h>
using namespace std;
//크루스칼 알고리즘
//가상의 노드를 생성해서 진행 
vector <tuple <int,int,int>> adj;
int parent[302];

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
        return false;

    if(x < y)
        parent[y] = x;
    else
        parent[x] = y;
    return true;
}

int main()
{
    int n;
    cin >> n;

    int cost;
    for(int i=1; i<=n; i++)
    {
        cin >> cost;
        adj.push_back({cost,0,i});
    }


    for(int i=1;i<=n; i++)
    {
        int cost_;
        for(int j=1; j<=n; j++)
        {
            cin >> cost_;
            if(i==j)
                continue;
            adj.push_back({cost_,i,j});
        }
    }
    
    for(int i=0; i<=n; i++)
        parent[i] = i;

    sort(adj.begin(), adj.end());

    int sum=0;
    int cnt=0;
    for(auto nxt : adj)
    {
        if(cnt == n)
            break;
        int cost, a, b;
        tie(cost,a,b) = nxt;
        if(Union(a,b))
        {
            sum+=cost;
            cnt++;
        }
    }

    cout << sum;
}
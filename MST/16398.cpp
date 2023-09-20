#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> adj;
int parent[1002];

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
    if(x<y)
        parent[y] = x;
    else
        parent[x] = y;
    return true;
}

int main()
{
    int n;
    cin >> n;
    for(int from=1; from<=n; from++)
    {
        int value;
        for(int to=1; to<=n; to++)
        {
            cin >> value;
            if(from == to)
                continue;
            adj.push_back({value,from,to});
        }
    }

    sort(adj.begin(), adj.end());

    for(int i=1; i<=n; i++)
        parent[i]=i;
    
    long long res=0; //결과의 자료형 생각하기
    int cnt=0;
    for(auto nxt: adj)
    {
        if(cnt == n-1)
            break;
        int cost,a,b;
        tie(cost,a,b) = nxt;
        if(Union(a,b))
        {
            res+=cost;
            cnt++;
        }
    }

    cout << res;
}
#include <bits/stdc++.h>
using namespace std;

pair <int,int> x[100002];
pair <int,int> y[100002];
pair <int,int> z[100002]; 

int parent[100002];

vector<tuple<int,int,int>> adj;

int find(int x)
{
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

bool Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y)
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

    int xv, yv, zv;
    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        cin >> xv >> yv >> zv;
        x[i] = make_pair(xv,i);
        y[i] = make_pair(yv,i);
        z[i] = make_pair(zv,i);
    }

    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    sort(z+1,z+n+1); 

    for(int i=1; i<n; i++)
    {
        adj.push_back({abs(x[i].first-x[i+1].first), x[i].second,x[i+1].second});
        adj.push_back({abs(y[i].first-y[i+1].first), y[i].second,y[i+1].second});
        adj.push_back({abs(z[i].first-z[i+1].first), z[i].second,z[i+1].second});
    }

    sort(adj.begin(),adj.end());

    long long sum = 0;
    int cnt = 0;
    for(auto nxt: adj)
    {
        if(cnt == n-1)
            break;
        int cost,a,b;
        tie(cost,a,b) = nxt;
        if(Union(a,b))
        {
            sum+=cost;
            cnt++;
        }
    }

    cout << sum;

}
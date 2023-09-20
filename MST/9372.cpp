#include <bits/stdc++.h>
using namespace std;

int parent[1002];
vector <pair<int,int>> adj;

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
        parent[y]=x;
    else
        parent[x]=y;
    return true;
}

int main()
{
    int test;
    cin >> test;

    while(test--)
    {
        int n,plane;
        cin >> n >> plane;

        int x,y;
        for(int i=1; i<=plane; i++)
        {
            cin >> x >> y;
            adj.push_back({x,y});
        }

        for(int i=1; i<=n; i++)
            parent[i]=i;

        int cnt=0;

        for(auto nxt: adj)
        {
            int a,b;
            a=nxt.first;
            b=nxt.second;
            if(Union(a,b))
                cnt++;
        }

        cout << cnt << '\n';
        adj.clear();
    }
}

//간단한 풀이
// #include <bits/stdc++.h>
// using namespace std;

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int t; cin >> t;
//   while(t--) {
//     int n, m;
//     cin >> n >> m;

//     int a, b;
//     while(m--) cin >> a >> b;
//     cout << (n-1) << '\n';
//   }
// }

// /*
// MST 문제라는 것을 파악했다면 (정점의 수)-1개의 간선이 필요하기 때문에
// 주어지는 입력을 받고 간선의 수를 출력하면 된다.
// */
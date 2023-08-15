#include <bits/stdc++.h>
using namespace std;
vector <int> adj[51];
int score[51];
bool vis[51];

int main()
{
    int n;
    cin >> n;

    while(1)
    {
        int x,y;
        cin >> x >> y;
        if(x==-1 && y==-1)
            break;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
    {
        queue <int> q;
        q.push(i);

        while(!q.empty())
        {
            
        }
        score[i] ++
    }
}
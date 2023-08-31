#include <bits/stdc++.h>
using namespace std;

bool vis[501];
vector <int> adj[501];
queue <int> q;
bool isTree;

void dfs(int cur, int prev)
{
    for(int nxt : adj[cur])
    {
        if(nxt == prev)
            continue;
        if(vis[nxt])
        {
            isTree = false;
            break;
        }
        vis[nxt] = true;
        dfs(nxt, cur);
    }
}

int main()
{
    int cnt = 0;
    while(1)
    {   
        cnt ++;
        int x,y;
        cin >> x >> y;
        if(x==0 && y==0)
            break;
        for(int i=1; i<=y; i++)
        {
            int x2,y2;
            cin >> x2 >> y2;
            adj[x2].push_back(y2);
            adj[y2].push_back(x2);
        }

        int tree_cnt=0;
    

        for(int i=1; i<=x; i++)
        {
            if(vis[i])
                continue;
            vis[i] = true;
            isTree = true;
            dfs(i,0);
            tree_cnt += isTree;
        }

        fill(vis,vis+501,0);
        for(int i=1; i<=x; i++)
            adj[i].clear();
    
        
        cout << "Case " << cnt << ": " ;
        if(tree_cnt == 0)
            cout << "No trees." <<'\n';
        else if(tree_cnt == 1)
            cout << "There is one tree."<< '\n';
        else    
            cout << "A forest of " << tree_cnt << " trees." << '\n';
    }
}

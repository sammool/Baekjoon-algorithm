#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool vis[101];

int main(){
    int n,connect;
    int cnt = 0;
    cin >> n;
    cin >> connect;

    for(int i=0 ;i<connect; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){

        int cur = q.front();
        q.pop();

        for(auto nxt: adj[cur]){
            if(vis[nxt])
                continue;
            vis[nxt] = true;
            q.push(nxt);
            cnt ++;
        }
    }
    cout << cnt;
}
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100001];
bool vis[100001];
int max_dist = -1;
int max_node = -1;

void dfs(int node, int dist){
    
    if(max_dist < dist){
        max_dist = dist;
        max_node = node;
    }
    
    vis[node] = 1;
    int cur = node;
    for(auto nxt: adj[cur]){
        if(vis[nxt.first])
            continue;
        dfs(nxt.first, dist+nxt.second);
    }
    
}

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y,dist,next;
        cin >> x >> y >> dist >> next;
        adj[x].push_back({y,dist});

        while(next!=-1){
            int dist2;
            cin >> dist2;
            adj[x].push_back({next,dist2});
            cin >> next;
        }
    }
    //입력 끝

    dfs(1,0);
    fill(vis,vis+100001,0);
    max_dist = -1;
    dfs(max_node,0);

    cout << max_dist;

}
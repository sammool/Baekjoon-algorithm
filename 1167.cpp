#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100001];
bool vis[100001];

void dfs(int node, int dist){
    vis[node] = 1;
    
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

}
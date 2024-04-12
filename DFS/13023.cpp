#include <bits/stdc++.h>
using namespace std;

vector<int> tree[2001];
bool vis[2001];
int n,m;
int result = 0;

void dfs(int cur, int length){
    if(length == 4){
        result = 1;
        return;
    }
    for(auto nxt: tree[cur]){
        if(vis[nxt])
            continue;
        vis[nxt] = true;
        dfs(nxt,length+1);
        vis[nxt] = false;
    }
        
}

int main(){
    
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    for(int i=0; i<n; i++){
        vis[i] = true;
        dfs(i,0);
        vis[i] = false;

        if(result){
            cout << result;
            return 0;
        }
    }
    cout << 0;
}
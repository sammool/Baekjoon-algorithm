#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101]; 
int dist[101]; 
int result[101];

int n,m;

int bfs(int start){ 
    queue<int> q; 
    q.push(start); 
    dist[start] = 0;

    while(!q.empty()){ 
        int cur = q.front(); 
        q.pop(); 
        for(auto nxt : adj[cur]){ 
            if(dist[nxt]!=0) 
                continue;
            dist[nxt] = dist[cur] + 1; 
            q.push(nxt);
        }
    } 
    int sum = 0; 
    for(int i=1; i<=n; i++){ 
        sum += dist[i];
        // cout << dist[i] << " ";
    }
    // cout << '\n';

    return sum; 
}

int main(){

cin >> n >> m;
for(int i=0; i<m; i++){
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}

for(int i=1; i<=n; i++){
    fill(dist,dist+n+1,0);
    result[i] = bfs(i);
}

int min = 10001;
int temp = 0;
for(int i=1; i<=n; i++){
    if(result[i] < min){
        min = result[i];
        temp = i;    
    }
}

cout << temp;
}
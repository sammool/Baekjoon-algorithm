// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int arr[1001][1001];
int dist[1001][1001];
bool vis[1001][1001];

int n,m;

void bfs(int x, int y){
    queue<pair<int,int>> q;
    dist[x][y] = 0;
    vis[x][y] = 1;
    q.push({x, y});
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int idx=0; idx<4; idx++){
            int nx = cur.X + dx[idx];
            int ny = cur.Y + dy[idx];
            
            if(nx<0||nx>=n||ny<0||ny>=m)
                continue;
            if(vis[nx][ny] || arr[nx][ny] == 0)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            vis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    
}
int main(){
    cin >> n >> m;
    
    int start_x = 0, start_y = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                start_x = i;
                start_y = j;
            }
            
            dist[i][j] = -1;
            if(arr[i][j] == 0)
                dist[i][j] = 0;
        }
    }
    
    
    bfs(start_x, start_y);
  
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}
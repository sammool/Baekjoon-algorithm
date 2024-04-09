#include <bits/stdc++.h>
using namespace std;

bool vis[55][55];
int arr[55][55];
queue<pair<int,int>> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int width,height;

void BFS(){
    
    while(!q.empty()){
            auto cur = q.front();
            q.pop();

            for(int dir=0; dir<4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx <0 || nx >=width || ny<0 || ny >= height)
                    continue;
                if(vis[ny][nx] || arr[ny][nx] !=1)
                    continue;
                vis[ny][nx] = 1;
                q.push({nx,ny});
            }
            
        }
}

int main() {
    
    int test;
    cin >> test;
    while(test--){
        int width, height, k;
        cin >> width >> height >> k;
        
        for(int i=0; i<k; i++){
            int x,y;
            cin >> x >> y;
            arr[y][x] = 1; //여기가 포인트 ㅠ
        }

        int cnt = 0;

        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(arr[i][j] && !vis[i][j])
                {
                    vis[i][j] =  true;
                    q.push({j,i});
                    BFS();
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}
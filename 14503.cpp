#include <bits/stdc++.h>
using namespace std;

int arr[51][51];
bool vis[51][51];
queue<pair<int,int>> q;
//동서남북
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n,m,x,y,dir;
int cnt = 0;

void clean(){
    if(!vis[x][y]){
        vis[x][y] = true;
        cnt++;
    }
}


int main() {
    cin >> n >> m;
    cin >> x >> y >> dir;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    }
    
    clean();

    while(1){
       
       bool isTrue = 0;
       
       for(int i=0; i<4; i++){
           dir = (dir+3-i)%4;
           int nx = x + dx[dir];
           int ny = y + dy[dir];
           if(nx<0||nx>=n||ny<0||ny>=m)
            continue;
           if(arr[nx][ny] || vis[nx][ny])
            continue;
           //4칸 중 청소되지 않은 칸 O
           x=nx;
           y=ny;
           isTrue=1;
           clean();
           break;
       }
       
       //4칸 중 청소되지 않은 칸 X
       if(!isTrue){
           int back = (dir+2)%4;
           int nx = x + dx[back];
           int ny = x + dy[back];
           if(nx<0 || nx >=n || ny<0 || ny >=m || arr[nx][ny])
            break;
           x=nx;
           y=ny;
           clean();
       }
    }
    cout << cnt;
    
}
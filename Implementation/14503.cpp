#include <bits/stdc++.h>
using namespace std;

int arr[51][51];
bool vis[51][51];

//북동서남
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

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

    while(1){
       
       clean();
       
       bool isTrue = 0;
       
       for(int i=0; i<4; i++){
           int nd = (dir+3-i)%4;
           int nx = x + dx[nd];
           int ny = y + dy[nd];
           if(nx<0 || nx>=n || ny<0 ||ny>=m )
            continue;
           if(arr[nx][ny] || vis[nx][ny])
            continue;
           //4칸 중 청소되지 않은 칸 O
           x=nx;
           y=ny;
           dir = nd;
           isTrue=1;
           break;
       }
       
       //4칸 중 청소되지 않은 칸 X
       if(!isTrue){
           int back = (dir+2)%4;
           int nx = x + dx[back];
           int ny = y + dy[back];
           if(arr[nx][ny])
            break;
           x=nx;
           y=ny;
       }
    }
    cout << cnt;
    
}
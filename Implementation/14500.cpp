#include <bits/stdc++.h>
using namespace std;

int board[501][501];
bool vis[501][501];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int result=0;
int n,m;

void dfs(int i, int j, int value, int cnt){
    if(cnt==4){
        if(result < value)
            result = value;
        return;
    }
    for(int idx=0; idx<4; idx++){
        int nx = i + dx[idx];
        int ny = j + dy[idx];
        if(nx<0||ny<0||nx>=n||ny>=m)
            continue;
        if(vis[nx][ny])
            continue;
        vis[nx][ny] = true;
        dfs(nx,ny,value+board[nx][ny],cnt+1);
        vis[nx][ny] = false;
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> board[i][j];
    }
    
    //보라색 제외한 테트로미노
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j] = true;
            dfs(i,j,board[i][j],1);
            vis[i][j] = false;
        }
    }
    //보라색 테트로미노
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i+2<n&&j+1<m){result = max(result,(board[i][j]+board[i+1][j]+board[i+1][j+1]+board[i+2][j]));}
            if(i+2<n&&j-1>=0){result = max(result,(board[i][j]+board[i+1][j]+board[i+1][j-1]+board[i+2][j]));}
            if(i+1<n&&j+1<m&&j-1>=0){result = max(result,(board[i][j]+board[i+1][j]+board[i+1][j+1]+board[i+1][j-1]));}
            if(i+1<n&&j+1<m&&j-1>=0){result = max(result,(board[i][j]+board[i+1][j]+board[i][j+1]+board[i][j-1]));}
        }
    }
    
    cout << result;
}
#include <bits/stdc++.h>
using namespace std;

char alpabat[30];
char board[21][21];

int dx[4] ={1,0,-1,0};
int dy[4] ={0,1,0,-1};

int r,c;
int result = 1;

bool checkCondition(int nx, int ny){
        if(nx>=r||ny>=c||nx<0||ny<0)
            return true;

        if(alpabat[board[nx][ny]-'A'])
            return true;

        return false;
}

void dfs(int row, int col, int count){
    for(int i=0; i<4; i++){
        int nx = row+dx[i];
        int ny = col+dy[i];

        if(checkCondition(nx,ny))
            continue;
        
        alpabat[board[nx][ny]-'A'] = true;
        result = max(result,count+1);
        
        dfs(nx,ny,count+1);
        alpabat[board[nx][ny]-'A'] = false;
    }
}

int main(){
   
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> board[i][j];
        }
    }

    alpabat[board[0][0]-'A'] = true;
    dfs(0,0,1);

    cout << result;
}
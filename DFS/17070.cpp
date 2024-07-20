#include <iostream>
using namespace std;

const int MAX_N = 20;

int board[MAX_N][MAX_N];
int dr[3] = {0,1,1};
int dc[3] = {1,0,1};
int N;
int result=0;

void DFS(int row, int col, int dir){

   if(row == N-1 && col == N-1){
        result++;
        return;
   }

   for(int i=0; i<3; i++){  //i=0 옆 i=1 밑 i=2 대각선
        if((dir == 0 && i==1) || (dir == 1 && i==0))
            continue;
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr >= N || nc >= N || board[nr][nc] == 1)
            continue;

        if(i == 2 && (board[nr-1][nc]==1 || board[nr][nc-1]==1))
            continue;
       
        DFS(nr,nc,i);
   }
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }
    DFS(0,1,0);
    cout << result;
}


#include <bits/stdc++.h>
using namespace std;

char arr[6][6];
bool vis[6][6];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int S_cnt = 0;
int cnt = 0;

void backTracking(int k){
    if(k == 7 && S_cnt >= 4){
        cnt++;
        return;
    }
    //BFS
    queue<char> q;
    auto cur = q.front();
    for(int idx=0; idx<4; idx++){
        int nx = cur.first + dx[idx];
        int ny = cur.second + dy[idx];
        if(nx<0 || nx>=5 || ny<0 || ny>=5)
            continue;
        if(vis[nx][ny])
            continue;
    }
    

}

int main(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++)
            cin >> arr[i][j];
    }
}
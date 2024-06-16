#include <bits/stdc++.h>
using namespace std;

int board[26][26];
int danji[500];
bool vis[26][26];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++){
            board[i][j] = str[j] - '0';
        }
    }
    
    
    int danji_cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            if(board[i][j] == 0 || vis[i][j] == 1)
                continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j] = true;
            danji[danji_cnt]++;
            
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for(int idx = 0; idx<4; idx++){
                    int nx = cur.first+dx[idx];
                    int ny = cur.second+dy[idx];
                    if(nx<0||ny<0||ny>=n||nx>=n)
                        continue;
                    if(vis[nx][ny]||board[nx][ny]==0)
                        continue;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                    danji[danji_cnt]++;
                }
            }
            danji_cnt++;
        }
    }
    
    sort(danji,danji+danji_cnt);
    cout << danji_cnt << '\n';
    for(int i=0; i<danji_cnt; i++){
        cout << danji[i] << '\n';
    }
    
}
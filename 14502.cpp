#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,m;
int board[9][9];
int temp[9][9];
bool vis[9][9];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<pair<int,int>> empty;
vector<pair<int,int>> virus;

int bfs(){

    int cnt = 0;

   for(auto nxt : virus){
        queue<pair<int,int>> q;
        q.push({nxt.X,nxt.Y});
        vis[nxt.X][nxt.Y] = true;

        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int idx=0; idx<4; idx++){
                int nx = cur.X + dx[idx];
                int ny = cur.Y + dy[idx];
                if(nx<0||ny<0||nx>=n||ny>=m)
                    continue;
                if(!vis[nx][ny] && temp[nx][ny] != 1 && temp[nx][ny] != 2)
                {
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
        }
   }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           cout << vis[i][j] << " ";
        }
        cout << '\n';
    }
   for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] == 0)
                cnt++;
            vis[i][j] = 0;
        }
    }

    return cnt;
}

int main(){
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                empty.push_back({i,j});
            }
            if(board[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }

    vector<int> v;
    for(int i=0; i<empty.size() -3; i++)
        v.push_back(0);
    for(int i=0; i<3; i++)
        v.push_back(1);

    int result = 0;
    do{
        copy(&board[0][0], &board[0][0] + 81, &temp[0][0]);
        for(int i=0; i<v.size(); i++){
            if(v[i] == 1){
                temp[empty[i].X][empty[i].Y] = 1;
            }
        }


        result = max(result,bfs());

    }while(next_permutation(v.begin(),v.end()));

    cout << result;
}
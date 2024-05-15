#include <bits/stdc++.h>
using namespace std;
//25C7의 조합
//연속된 7개
//S가 4개 이상
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char arr[6][6];
int adj[6][6];
bool vis[6][6];

bool bfs(vector<pair<int,int>> & v){
    int cnt=0,cnt_s=0;
    queue<pair<int,int>> q;
    
    for(int i=0; i<7; i++){
        if(arr[v[i].first][v[i].second] == 'S')
            cnt_s++;
    }
    if(cnt_s < 4)
        return false;

   
    q.push({v[0].first,v[0].second});
    vis[v[0].first][v[0].second] = 1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        cnt++;

        for(int idx=0; idx<4; idx++){
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            if(nx<0 || nx>=5 || ny<0 || ny>=5)
                continue;
            if(vis[nx][ny] || !adj[nx][ny])
                continue;
            q.push({nx,ny});
            vis[nx][ny] = 1;
        }
    }
    if(cnt == 7)
        return true;
    else
        return false;
    
}

int main(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> v;
    vector<pair<int,int>> v2;

    for(int i=0; i<7; i++)
        v.push_back(0);
    for(int i=0; i<25-7; i++)
        v.push_back(1);
    
    int ans=0;

    do{
        for(int i=0; i<25; i++){
            if(v[i] == 0){
                v2.push_back({(i/5),(i%5)});
                adj[i/5][i%5] = 1;
            }
        }
        if(bfs(v2))
            ans++;
        for(int i=0; i<5; i++){
            fill(adj[i],adj[i]+5,0);
            fill(vis[i],vis[i]+5,0);
        }
        
        v2.clear();

    }while(next_permutation(v.begin(), v.end()));

    cout << ans;

}


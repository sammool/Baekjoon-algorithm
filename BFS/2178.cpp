#include <iostream>
#include <queue>
using namespace std;

int main() {

string mir[101];
int dis[101][101];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n,m;

cin >> n >> m;
for(int i=0; i<n; i++)
    cin >> mir[i];

for(int i=0; i<n; i++)
    fill(dis[i],dis[i]+m,-1);     //밑의 if조건에서 0보다 작게하기 위해

queue<pair<int,int>> q;
dis[0][0]=0;
q.push({0,0});

while(!q.empty())
{
    auto cur=q.front();
    q.pop();
    for(int dir=0; dir<4; dir++)
    {
        int nx=cur.first+dx[dir];
        int ny=cur.second+dy[dir];
        if(nx<0 ||nx>=n || ny<0 || ny>=m)
            continue;
        if(dis[nx][ny]>=0 || mir[nx][ny]!='1') //첫번째로 다시 못오게
            continue;
        dis[nx][ny]=dis[cur.first][cur.second]+1;
        q.push({nx,ny});
    }
}
cout << dis[n-1][m-1]+1;

return 0;
}
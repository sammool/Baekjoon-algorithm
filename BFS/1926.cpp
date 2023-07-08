#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    int drw[501][501];
    bool vis[501][501];

    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin >> drw[i][j];
    }
    queue<pair<int,int>> q;

    int max_area=0;
    int num=0;
    for(int i=0; i<n; i++)
    {
        
        for(int j=0; j<m; j++)
        {
            
            if(vis[i][j]==1 || drw[i][j]==0 )
                continue;
            num++;
            vis[i][j]=1;
            q.push({i,j});
            int area=0;

            while(!q.empty())
            {
                area++;
                pair<int,int> cur=q.front();
                q.pop();

                for(int dir=0; dir<4; dir++)
                {
                    int nx=cur.first+dx[dir];
                    int ny=cur.second+dy[dir];
                    if(nx<0 || nx>=n || ny<0 ||ny>=m)
                        continue;
                    if(vis[nx][ny]==1 || drw[nx][ny]!=1)
                        continue;
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                   
                }
            }
            if(area>max_area)
                max_area=area;
        }
    }
    cout<<num<<'\n'<<max_area;
}
//1 1
//1 1 일때??
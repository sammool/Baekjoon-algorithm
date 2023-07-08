#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int box[1001][1001];
    int day[1001][1001];

    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    int M,N;
    cin >> M >> N;

    queue<pair<int,int>> q;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
            cin>>box[i][j];
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(box[i][j]==1)
                q.push({i,j});

            if(box[i][j]==0)
                day[i][j]=-1;
        }
    }


    while(!q.empty())
    {
        auto cur=q.front();
        q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if(nx<0 || nx>=N || ny<0 ||ny>=M)
                continue;
            if(day[nx][ny]>=0)
                continue; 
            day[nx][ny]=day[cur.first][cur.second]+1;
            q.push({nx,ny});
          
        }
    }
 
    int max=day[0][0];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(day[i][j]==-1)
            {
                cout<<-1;
                return 0;
            }
            if(day[i][j]>max)
                max=day[i][j];
        }
    }

    cout << max;


}
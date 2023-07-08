#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int dist[100001];
    int N,K;

    cin >> N >> K;
    
    fill(dist,dist+100001,-1);

    dist[N]=0;
    queue <int> q;
    q.push(N);

    if(N==K)
    {
        cout<< 0;
        return 0;  //처음부터 위치가 같은 경우
    }

    while(!q.empty())
    {
        auto cur=q.front();
        q.pop();
        for(int nx: {cur-1,cur+1,2*cur})
        {
            if(nx<0 || nx>100000)
                continue;
            if(dist[nx]!=-1)
                continue; //이미 갔던 곳은 다시 가도 시간 줄이기 불가능
            dist[nx]=dist[cur]+1;
            q.push(nx);
            if(nx==K)
            {
                cout<<dist[nx];
                return 0;
            }

        }
    }
}
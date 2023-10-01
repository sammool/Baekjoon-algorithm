#include <bits/stdc++.h>
using namespace std;

int cost[202][202];
int close[202];
int infi = 0xffff;

int main()
{
    int n,m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++)
    {
        fill(cost[i],cost[i]+n+1,infi);
        cost[i][i] = 0;
    }

    int x,y,to;
    for(int i=1; i<=m; i++)
    {
        cin >> x >> y >> to;
        cost[x][y] = to;
    }
    int Friend;
    cin >> Friend;

    for(int i=1; i<=Friend; i++)
        cin >> close[i];

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
        }
    }

    vector <pair<int,int>> goback;
    //각 도시마다 최대 왕복시간을 구한다
   for(int i=1; i<=n; i++)
   {
        int max = 0;
        for(int j=1; j<=Friend; j++)
        {
            if(max < cost[close[j]][i] + cost[i][close[j]])
                max = cost[close[j]][i] + cost[i][close[j]];      
        }
        goback.push_back({max,i});
   }
   sort(goback.begin(), goback.end());

    auto min = goback.front();
    for(auto ele : goback)
    {
        if(ele.first == min.first)
            cout << ele.second << " ";
        else
            break;
    }
}
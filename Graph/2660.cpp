#include <bits/stdc++.h>
using namespace std;
vector <int> adj[51];
int score[51];
int dist[51];

int main()
{
    int n;
    cin >> n;

    while(1)
    {
        int x,y;
        cin >> x >> y;
        if(x==-1 && y==-1)
            break;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
    {
        fill(dist,dist+51,-1);

        queue <int> q;
        q.push(i);
        dist[i] = 0;
        
        while(!q.empty())
        {
            int cnt = 0;
            int cur = q.front();
            q.pop();

            for(int nxt : adj[cur])
            {
                if(dist[nxt]> -1)
                    continue;
            
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }    
            score[i] = *max_element(dist,dist+51);
        }
      
    }
    
    int min = *min_element(score+1,score+n-1);
    int cnt = 0;
    vector <int> v;
    for(int i=1; i<=n; i++)
    {
        if(score[i] == min)
        {
            cnt++;
            v.push_back(i);
        }
    }
    cout << min <<" " << cnt << '\n';
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
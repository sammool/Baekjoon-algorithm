#include <bits/stdc++.h>
using namespace std;

vector <int> party[51];
bool t_or_f[51];
bool party_res[51];
int main()
{
    int n,m;
    cin >> n >> m;
    int truth;
    cin >> truth;
    
    for(int i=0; i<truth; i++)
    {
        int x;
        cin >> x;
        t_or_f[x] = true;
    }
    
    for(int i=1; i<=m; i++)
    {
        int x;
        cin >> x;
        for(int j=1; j<=x; j++)
        {
            int person;
            cin>>person;
            party[i].push_back(person);
        }
    }
    for(int i=1; i<=m; i++)
    {
        queue <int> q;
        q.push(i);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int nxt : party[cur])
            {
                if(t_or_f[nxt])
                    
            }
        }
    }

}
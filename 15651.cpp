#include <iostream>
using namespace std;

int arr[9];
bool vis[9];
int n,m;

void backtracking(int k, int h)
{
    if(m==k)
    {
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }

    for(int i=1; i<=n; i++)
    {
        vis[h]=0;

        if(!vis[i])
        {
            arr[k]=i;
            vis[i]=1;
            backtracking(k+1, i);
            vis[i]=0;
        }
    }
}

int main()
{
    cin >> n >> m;
    backtracking(0,0);
}
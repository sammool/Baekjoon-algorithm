#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int save[9];
bool vis[9];
int n,m;

void back_track(int k)
{
    if(m==k)
    {
        for(int i=0; i<m; i++)
            cout<<save[i]<<' ';
        cout<<'\n';
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            save[k]=arr[i-1];
            vis[i]=1;
            back_track(k+1);
            vis[i]=0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr,arr+n);
    
    back_track(0);
}

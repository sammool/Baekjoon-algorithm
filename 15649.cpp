#include <iostream>
using namespace std;

int arr[9];
bool vis[9];
int n,m;

void func(int k)
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
        if(!vis[i])
        {
            arr[k]=i;
            vis[i]=1;
            func(k+1);
            vis[i]=0;
        }
    }
}

int main()
{
    cin >> n >> m;
    func(0);
}

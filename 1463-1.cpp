#include <iostream>
#include <queue>
using namespace std;
int arr[1000002];


int main()
{
   
    int x;
    cin >> x;

    if(x==1)
    {
        cout << 0;
        return 0;
    }
    queue <int> q;
    q.push(x);

    fill(arr,arr+1000002,-1);
    arr[x]=0;

    while(!q.empty())
    {
        int nx;
        auto cur=q.front();
        q.pop();
        if(cur<1)
            break;
        
        if(cur%3==0 && arr[cur/3]<0)
        {
            nx=cur/3;
            arr[nx]=arr[cur]+1;
            q.push(nx);
        }
        if(cur%2==0 && arr[cur/2]<0)
        {
            nx=cur/2;
            arr[nx]=arr[cur]+1;
            q.push(nx);
        }
        if(arr[cur-1]<0)
        {
            nx=cur-1;
            arr[nx]=arr[cur]+1;
            q.push(nx);
        }
    }

    cout<<arr[1];
}

//x->13 12 
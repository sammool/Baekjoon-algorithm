#include <iostream>
using namespace std;

int main()
{
    int arr[100009];
    bool vis[100009];
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int en = 0;
    long result = 0;
    for(int st=0; st<n; st++)
    {
        while(en < n)
        {   
            if(vis[arr[en]])
                break;
            vis[arr[en]]=1;
            en++;
        }
        result += en - st  ;
        
        vis[arr[st]] = false;

    }

    cout << result;
}
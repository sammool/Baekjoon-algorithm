#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[100001];

    int n,s;
    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int result = 100001;

    for(int st=0; st<n; st++)
    {
        int sum=arr[st];
        int en=st+1;
        
        while(sum < s && en < n)
            sum+=arr[en];
        
        if(en==n)
            continue;
        result=min(result, en-st+1);
        
    }

    cout << result;

}
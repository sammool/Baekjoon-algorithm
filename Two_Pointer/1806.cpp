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

    int sum = arr[0];
    int en = 0;
    
    for(int st=0; st<n; st++)
    {
        while(sum < s && en < n)
        {    
            en++;
            sum+=arr[en];
        }

        if(en==n)
            break;
        result=min(result, en-st+1);

        sum = sum - arr[st];
        
    }
    if(result == 100001)
        result = 0;
    cout << result;

}
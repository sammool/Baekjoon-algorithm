#include <iostream>
using namespace std;

int arr[100001];

int main()
{
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    int result = 0;
    int cnt = 0;
    int st=0, en=0;
    if(arr[0] % 2 == 1) cnt++;
    for(int st=0; st<n; st++)
    {
        while(en < n-1 && cnt + arr[en+1]%2 <=k)
        {
            en++;
            cnt+=arr[en]%2;
        }

        result= max(result, en-st+1-cnt);
        cnt-=arr[st]%2;
    }
    cout << result;
    
}
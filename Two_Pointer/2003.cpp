#include <iostream>
using namespace std;

int main()
{
    int A[10001];
    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> A[i];

    int cnt=0;
    int sum=A[0], en=0;
    for(int st=0; st<n; st++)
    {
        while(en < n-1&& sum < m)
        {
            en++;
            sum+=A[en];
        }
        if(sum == m)
            cnt++;
        sum-=A[st];
    }
    cout << cnt;
}
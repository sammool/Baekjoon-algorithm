#include <iostream>
#include <algorithm>
using namespace std;

int A[100001];

int binary_search(int k, int n)
{
    int st = 0;
    int en = n-1;
  

    while(st<=en)
    {
        int mid = (st+en) / 2;
        if(k>A[mid])
            st=mid+1;
        else if(k<A[mid])
            en=mid-1;
        else 
            return 1;
    }

    return 0;

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];
    sort(A,A+n);

    int m,k;
    cin >> m;
    for(int i=0; i<m; i++)
    {
         cin >> k;
         cout << binary_search(k,n) << '\n';        
    }

}
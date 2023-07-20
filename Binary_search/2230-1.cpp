#include <iostream>
#include <algorithm>
using namespace std;

long A[100001];

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> A[i];
    sort(A,A+n);

    long min=2000000001;
    
    for(int i=0; i<n; i++)
    {   
        int tmp = lower_bound(A, A+n, A[i]+m)- A;
        
        if(A[tmp]-A[i]<min && A[tmp]-A[i]>=m)
            min=A[tmp]-A[i];
           
    }
    cout << min;
}
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

    long Min=2000000001;


    int en=0;
    for(int st=0; st<n; st++)
    {
        while(A[en]-A[st] < m && en < n )
            en++;
        if(en==n)
            break;
        Min=min(Min,A[en]-A[st]);
    }
    cout << Min;
}
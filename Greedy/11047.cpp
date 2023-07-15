#include <iostream>
using namespace std;

int value[11];

int main()
{
    int n,k;
    int cnt=0;
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> value[i];
    }

    for(int i=n-1; i>=0; i--)
    {
        cnt+=k/value[i];
        k=k%value[i];     //value[i]=value[i-1] 의 배수이기 때문에 가능
    }
    cout << cnt;

}
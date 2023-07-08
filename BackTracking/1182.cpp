#include <iostream>
using namespace std;
int n,s;
int cnt=0;
int arr[22];

void func(int k, int sum)
{
    if(n==k)
    {   
        if(sum==s)
            cnt++;
        return;
    }

    func(k+1, sum);
    func(k+1, sum+arr[k]);
}

int main()
{
    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    func(0,0);
    if(s==0)
        cnt--;
    cout << cnt;
}

//공집합은 0
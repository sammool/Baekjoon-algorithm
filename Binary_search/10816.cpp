#include <iostream>
#include <algorithm>
using namespace std;

int A[500001];
int n;

int left(int k)
{
    int st = 0;
    int en = n;
  
    while(en > st)
    {
        int mid = (st+en) / 2;
        if(A[mid] >= k)
            en=mid;

        else if(A[mid] < k)
            st=mid+1;
    }
    return st;
    // k가 들어갈 수 있는 인덱스를 생각하자
}

int right(int k)
{
    int st = 0;
    int en = n;
  
    while(en > st)
    {
        int mid = (st+en) / 2;
        if(A[mid] >k)
            en=mid;

        else if(A[mid] <= k)
            st=mid+1;
    }
    return st;
    // k가 들어갈 수 있는 인덱스를 생각하자
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);         //무조건 넣자 안넣으면 틀림
   
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> A[i];
    
    sort(A,A+n);

    int m,k;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        cin >> k;
        cout << right(k) - left(k) << " ";
    }

}
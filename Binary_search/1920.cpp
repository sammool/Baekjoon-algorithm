#include <bits/stdc++.h>

using namespace std;

int n;
int A[100001];

int binary_search(int k)
{
    int st = 0;
    int en = n-1;
  
	
    while(st<=en)
    {
        int mid = (st+en) / 2;
        
        //A[mid] < 찾고자하는 값일 때 st = mid + 1
        if(A[mid] < k)
            st=mid+1;
        
        //A[mid] > 찾고자하는 값일 때 en = mid - 1
        else if(A[mid] > k)
            en=mid-1;
        
        //A[mid] == 찾고자하는 값일 때 반복문을 빠져나온다
        else 
            return 1;
    }
	
    //st와 en이 역전되면 값이 없는 것이므로 탐색을 중지한다
    return 0;

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];
   
   //배열 오름차순으로 정렬
   sort(A,A+n);

    int m,k;
    cin >> m;
    for(int i=0; i<m; i++)
    {
    	//찾고자 하는 값을 입력받고 binary_search함수를 
        //통해 값이 있는지 확인한다.
         cin >> k;
         cout << binary_search(k) << '\n';        
    }

}
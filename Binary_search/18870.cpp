#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <int> A(1000001);
vector <int> B(1000001);

int binary_search(int k)
{
    int st=0;
    int en=A.size()-1;
    while(en > st)
    {
        int mid= (st+en) / 2;
        if(k < A[mid])
            en=mid-1;
        else if(k > A[mid])
            st=mid+1;
        else
            en=mid;
    }
    return st;

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
        B[i]=A[i];
    }   
    
    sort(A.begin(),A.begin()+n);
    A.erase(unique(A.begin(),A.begin()+n),A.end());  

    for(int i=0; i<n; i++)
      cout << binary_search(B[i]) << " ";
}
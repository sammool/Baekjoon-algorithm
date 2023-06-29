#include <iostream>
using namespace std;

int func(int n, int r, int c)
{
    int half=(1<<n)/2 ;

    if(n==0)
        return 0;
    
    if(r<half && c<half)
        return func(n-1, r, c);  //1번째
    
    else if(r<half && c>=half) 
        return half*half + func(n-1, r, c-half);  //2번째
    
    else if(r>=half && c<half)
        return 2*half*half +func(n-1,r-half, c);      //3번째
        
    else if(r>=half && c>=half)
        return 3*half*half +func(n-1, r-half, c-half);
}
int main()
{
    int N, r ,c;
    cin >> N >> r >> c;
    cout << func(N, r ,c);
}
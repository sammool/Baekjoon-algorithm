#include <iostream>
using namespace std;

void func(int n, int a, int b)
{
    if(n==1)
    {
        cout << a << ' ' << b <<'\n';
        return;
    }
    
    func(n-1, a, 6-a-b);
    cout << a <<' ' << b << '\n';
    func(n-1, 6-a-b, b);
}

int main()
{
    int N;
    cin >> N;
    cout<< (1<<N)-1 <<'\n';
    func(N,1,3);
}
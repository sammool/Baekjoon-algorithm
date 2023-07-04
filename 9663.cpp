#include <iostream>
using namespace std;

bool isused1[40];
bool isused2[40];
bool isused3[40];
int N;
int cnt=0;


void func(int k)
{
    if(N==k)
    {
        cnt++;
        return;
    }
    for(int i=0; i<N; i++)
    {
        if(isused1[i] || isused2[i+k] || isused3[k-i+N-1])
            continue;
        isused1[i]=1;
        isused2[k+i]=1;
        isused3[k-i+N-1]=1;
        func(k+1);
        isused1[i]=0;
        isused2[k+i]=0;
        isused3[k-i+N-1]=0;
    }
   
}

int main()
{
    cin >> N;
    func(0);
    cout<<cnt;
}

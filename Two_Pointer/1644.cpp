#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector <bool> state (n+5, true);
    vector <int> prime;
    
    for(int i=2; i<=n; i++)
    {
        if(!state[i])
            continue;   
        for(int j= 2*i; j<=n; j+=i)
            state[j]=false;
    }

    for(int i=2; i<=n; i++)
    {
        if(state[i])
            prime.push_back(i);
    }

    int sum=prime[0];
    int cnt=0;
    int en=0;
    int size = prime.size();
    //소수 구하기는 완료

    for(int st=0; st<size; st++)
    {
        while(sum < n && en <n)
        {
            en++;
            sum+=prime[en];
        }
        if(sum == n)
            cnt++;

        if(en == size)
            break;
        sum -= prime[st];
    }
    cout << cnt;
}
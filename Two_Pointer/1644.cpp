#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    if(n==1)
    {
        cout << "0";
        return 0;
    }

    vector <bool> state (n+1, true);
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
    //소수 구하기

    int sum=prime[0];
    int cnt=0;
    int en=0;
    int size = prime.size();


    for(int st=0; st<size; st++)
    {
        while(sum < n && en < size)
        {
            en++;
            if(en==size)          // en == size가 되면 size범위 초과
                break;
            sum+=prime.at(en);
        }
        if(sum == n)
            cnt++;

        sum -= prime.at(st);
    }
    cout << cnt;
}
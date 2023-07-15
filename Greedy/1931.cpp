#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int cnt=1;
    cin >> n;

    pair <int,int> mt[100001];
    for(int i=0; i<n; i++)
    {
        cin >> mt[i].second >> mt[i].first;
    }    
    sort(mt, mt+n);
    
    auto arr=mt[0];
    for(int i=1; i<n; i++)
    {
        if(mt[i].second >= arr.first)
        {
            cnt++;
            arr=mt[i];
        }
    }
    cout << cnt;
}
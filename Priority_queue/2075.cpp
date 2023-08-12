#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int,vector<int>, greater<int>> pq;
    int n;
    cin >> n;

    for(int i=0; i<n*n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);

        if(n<pq.size())
            pq.pop();
    }
    
    cout << pq.top();
}

//메모리 초과를 막기 위해 계속해서 지워준다
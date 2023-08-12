#include <iostream>
#include <queue>


int main()
{
    using namespace std;
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t_case;
    cin >> t_case;
    for(int i=0; i<t_case; i++)
    {

        priority_queue <long long, vector<long long>, greater<long long>> pq;

        int n;
        cin >> n;
        
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        
        long long sum=0;
        
        while(pq.size() > 1)
        {
            long long a =pq.top();
            pq.pop();
           
            long long b =pq.top();
            pq.pop();
           
            sum+=a+b;
            pq.push(a+b);
        }

        cout << sum << '\n';
    }
}
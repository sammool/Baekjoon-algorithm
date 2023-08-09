#include <bits/stdc++.h>

using namespace std;

class compare{
    public:
        bool operator()(const int& a, const int& b)
        {
            if(abs(a) != abs(b))
                return abs(a) > abs(b);  //내림차순
            return a>b;
            //절대값이 같을때 음수가 루트로 가게 한다
        }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue <int, vector<int>, compare> pq;

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        if(x==0)
        {
            if(pq.empty())
                cout << 0 << '\n';
            else
            {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else
            pq.push(x);
        
    }
}
#include <iostream>
#include <queue>

using namespace std;


int main() 
{
    
    priority_queue <int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int result = 0;
    while(pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        result+=a+b;
        pq.push(a+b);
    }
  
    cout << result;
}
//계속해서 최솟값을 갱신하기 위에 힙에 갱신한다
//ex) 2 2 3 3 처음엔 (2+2) + (4+3) + (7+3) =21인줄 알았으나
//(2+2) + (3+3) + (4+6) = 20 으로 만들기 위해 2+2=4를 힙에 추가

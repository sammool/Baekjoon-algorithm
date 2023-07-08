#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st;
    int N,n;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> n;
        if(n!=0)
            st.push(n);
        else
            st.pop();
    }

    int sum=0;
    while(!st.empty())
    {   
        sum+=st.top();
        st.pop();
    }
    cout << sum;
  }

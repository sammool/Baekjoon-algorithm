#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string s;
    while(1)
    {
        bool isValue=true;
        getline(cin,s);

        if(s==".")
            break;
        stack <char> st;
        for(auto &e: s)
        {
            if(e=='(' ||e=='[')
                st.push(e);
            else if(e==')')
            {
                if(st.empty() || st.top()!='(')
                 {
                    isValue=false;
                    break;
                }
                else 
                    st.pop();
            }
                
            else if(e==']')
            {
                if(st.empty() || st.top()!='[')
                {
                    isValue=false;
                    break;
                }
                else 
                    st.pop();
            }
        }

        if(!st.empty())
            isValue=false;
        if(isValue)
            cout << "yes" << '\n';
        else
             cout << "no" << '\n';

    }
}
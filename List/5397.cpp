#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    list <char> li;
    list <char>::iterator itr;
    
    int N;
    string str;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        li.clear();
        itr=li.begin();
         cin >> str;
    
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]=='<' )
            {
                if(itr!=li.begin())
                    itr--;
            }
            
            else if(str[i]=='>' )
            {
                if(itr!=li.end())
                    itr++;
            }
            
            else if(str[i]=='-' )
            {
                if(itr!=li.begin())
                    itr=li.erase(--itr); //erase는 iterator 반환 o
            }
            
            else
            {
                li.insert(itr,str[i]); //insert는 iterator 반환 x
            }
        }
       
        for(itr=li.begin(); itr!=li.end(); itr++)
            cout<<*itr;
        

        cout<<'\n';
    }
}
//B itr:0 now 1
//커서가 iterator 문자가 리스트라고 생각

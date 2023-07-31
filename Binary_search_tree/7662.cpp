#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
   
    for(int i=0; i<t; i++)
    {  
        multiset <int> q;
        int n;
        cin >> n;
       
        for(int i=0; i<n; i++)
        { 
            int value;
            char option;
            cin >> option >> value;
            
            if(option == 'I')
             {
                q.insert(value);
             }   
            
            else if(option == 'D')
            {
                if(q.empty())
                    continue;  
                if(value == 1 )
                    q.erase(prev(q.end()));
                else
                    q.erase(q.begin());
            } 
        }

        if(q.empty())
            cout << "EMPTY" << '\n';
        else
            cout  << *prev(q.end()) << " " << *q.begin()<<'\n';
           
    }
    
}
#include <iostream>
#include <map>
#include <set>
using namespace std;

map <int, int> list; //key가 번호
set <pair<int,int>> level; //key가 난이도

int main()
{

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int number, n_level;
        cin >> number >> n_level;
        level.insert({n_level,number});
        list[number] = n_level;
    }

    int m; 
    cin >> m;
    for(int i=0; i<m; i++)
    {
        string option;
        cin >> option;

        if(option == "recommend")
        {
            int x;
            cin >> x;
            if(x == 1)
                cout << (*prev(level.end())).second << '\n';
            else    
                cout << (*level.begin()).second << '\n';

        }

        else if (option == "add")
         {
            int n_level,number;
            cin >> number >> n_level;
            level.insert({n_level, number});
            list[number] = n_level;
        }

        else
        {
            int number;
            cin >> number;
            level.erase({list[number], number});
            list.erase(number);
         }
    }
}
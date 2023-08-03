#include <iostream>
#include <map>
using namespace std;

map<int, int> list;

void Recommend()
{
    int x;
    cin >> x;
    if(x == 1)    
        cout << prev(list.end())->second;
    else
         cout << list.begin()->second;
}

void Add()
{
    int level,number;
    cin >> level >> number;
    list.insert(level,number);
}

void Solved()
{
    
}

int main()
{

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int number,level;
        cin >> number >> level;
        list.insert(level,number);
    }

    int m; 
    cin >> m;
    for(int i=0; i<m; i++)
    {
        string option;
        cin >> option;

        if(option == "recommend")
            Recommend();
        else if (option == "add")
            Add();
        else 
            Solved();
    }
}
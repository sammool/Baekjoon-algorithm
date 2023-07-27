#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map <string,int> book;

    int n,quiz;
    cin >> n >> quiz;
    for(int i=1; i<n; i++)
    {
        string pocket;
        cin >> pocket;
        book[pocket]=i;
    }
    for(int i=1; i<=quiz; i++)
    {
        string _s;
        cin >> _s;
        if(isdigit(_s[0]))
            cout << 

    }
    
}
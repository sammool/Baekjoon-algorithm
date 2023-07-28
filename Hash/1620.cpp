#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map <string,int> book;
    string s[100001];

    int n,quiz;
    cin >> n >> quiz;
    for(int i=1; i<=n; i++)
    {
        string pocket;
        cin >> pocket;
        
        s[i] = pocket;
        book[pocket] = i;
    }
    for(int i=1; i<=quiz; i++)
    {
        string _s;
        cin >> _s;
        if(isdigit(_s[0]))
            cout << s[stoi(_s)] << '\n';
        else    
            cout << book[_s] << '\n';
   }
    
}
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b)
{
    if(a > b)
        return 1;
    else
        return 0;
}

int main()
{
    unordered_set <string> member;

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string name, in;
        cin >> name >> in;
        if(in == "enter")
            member.insert(name);
        else if(in == "leave")
            member.erase(name);
    }
    
    vector <string> v(member.begin(), member.end());
   
    sort(v.begin(), v.end(), compare);
  
    for(auto &e : v)
        cout << e << '\n';
}
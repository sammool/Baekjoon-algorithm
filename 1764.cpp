#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    set<string> s;
    vector<string> v;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        s.insert(str);
    }

    for(int i=0; i<m; i++){
        string str;
        cin >> str;
        if(s.find(str) == s.end())
            continue;
        string temp = *s.find(str);
        v.push_back(temp);

    }

    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }

}
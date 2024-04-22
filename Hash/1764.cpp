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
    
    int cnt = 0;
    for(int i=0; i<m; i++){
        string str;
        cin >> str;
        if(s.find(str) == s.end())
            continue;
        string temp = *s.find(str);
        cnt ++ ;
        v.push_back(temp);

    }

    sort(v.begin(),v.end());
    cout << cnt << '\n';
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }

}
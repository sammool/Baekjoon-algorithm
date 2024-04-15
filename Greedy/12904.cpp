#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    
    /*length와 size모두 null제외하고 알려줌
      length=O(n), size=O(1)*/
    
    int idx = t.size()-1;
    while(s.size() < t.size()){
        if(t[idx] == 'A'){
            //idx의 문자만 제거, size줄어듦
            t.erase(idx,idx+1);
        }
        else{
            t.erase(idx,idx+1);
            reverse(t.begin(), t.end());
        }
        idx--;
    }
    if(s == t)
        cout << 1;
    else
        cout << 0;
}
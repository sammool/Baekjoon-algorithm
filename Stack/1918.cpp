#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    stack<char> stk;

    cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='A' && s[i]<='Z'){
            cout << s[i];
        }
        else{
            if(s[i]=='*' || s[i]=='/'){
                while(!stk.empty() && (stk.top()=='*' || stk.top()=='/')){
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
            else if(s[i]=='+'||s[i]=='-'){
                while(!stk.empty() && stk.top()!='('){
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
            else if(s[i] == '(') {stk.push(s[i]);}
            
            else{
                while(!stk.empty() && stk.top()!='('){
                    cout << stk.top();
                    stk.pop();
                }
                stk.pop();
            }
        }
    }
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
}
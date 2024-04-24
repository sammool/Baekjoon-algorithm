#include <bits/stdc++.h>
using namespace std;

int main(){
    
   ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 0; //int = 4Byte = 23Bit
    int m;
    cin >> m;
    for(int i=0 ;i<m; i++){
        string s;
        cin >> s;
        
        if(s == "add"){
            int x;
            cin >> x;
            n|= (1 << x); //x번째가 켜짐
        }
        else if(s == "remove"){
            int x;
            cin >> x;
            n&= ~(1 << x);
        }
        else if(s == "check"){
            int x;
            cin >> x;
            if(n& (1<<x))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(s == "toggle"){
            int x;
            cin >> x;
            if(n& (1 << x))
                n&= ~(1 << x);
            else
                n|= (1 << x);
        }
        else if(s == "all"){
            n|= (1 << 21) - 1;
        }
        else
            n = 0;
    }
    return 0;
}
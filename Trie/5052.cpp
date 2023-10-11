#include <bits/stdc++.h>
using namespace std;
const int MX = 10 * 10000 + 3;
const int ROOT = 1;

int unused = 2;
int nxt[MX][10];
bool chk[MX];

int c2i(char c){
    return c-'0';
}

void insert(string &s){
    int cur = ROOT;
    for(auto c : s){
        if(nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(string &s){
    int cur = ROOT;
    for(auto c : s){
       if(chk[nxt[cur][c2i(c)]])
            return true;
        cur = nxt[cur][c2i(c)];
    }
    return false;
}

int main()
{
    int t_case;
    cin >> t_case;
    
    for(int i=0; i<=MX; i++)
        fill(nxt[i],nxt[i]+10, -1);
    
    fill(chk,chk+MX,0);

    int n;
    for(int i=0; i<t_case; i++)
    {
        cin >> n;
        string str;
        int cnt = 0;
        for(int i=0; i<n; i++){
            cin >> str;
            if(find(str))
                cnt++;
            insert(str);
        }
        if(cnt)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}
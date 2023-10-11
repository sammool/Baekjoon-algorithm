#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 500 * 10000 + 3;
int nxt[MX][26];

int c2i(char c){
    return c-'a';
}

void insert(string & s){
    int cur = ROOT;
    for(auto c : s){
        if(nxt[cur][c2i(c)] == -1)  
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
}

bool find(string &s){
    int cur = ROOT;
    for(auto c : s){
        if(nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return true;
}

int main()
{
    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<=MX; i++)
        fill(nxt[i],nxt[i]+26,-1);

    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        insert(str);
    }

    string test;
    int cnt = 0;
    for(int i=0; i<m; i++)
    {
        cin >> test;
        if(find(test))
            cnt++;
    }

    cout << cnt;
}
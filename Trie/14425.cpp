#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 3;
int nxt[MX][26];
bool chk[MX];

int c2i(char c){
    return c-'a';
}

void insert(string &s)
{
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
        if(nxt[cur][c2i(c)]==-1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

void erase(string &s){
    int cur = ROOT;
    for(auto c:s){
        if(nxt[cur][c2i(c)]==-1)
            return;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = false;
}

int main()
{
    for(int i=1; i<=MX; i++)
        fill(nxt[i],nxt[i]+26,-1);

    int n,m;
    cin >> n >> m;
    
    string s;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        insert(s);
    }

    string test;
    int cnt=0;
    for(int i=0; i<m; i++)
    {
        cin >> test;
        if(find(test))
            cnt++;
    }

    cout << cnt;
}
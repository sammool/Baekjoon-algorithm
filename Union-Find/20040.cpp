#include <bits/stdc++.h>
using namespace std;

int parent[500001];

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

bool Union(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y)
        return false;
    else if(x < y)
        parent[y] = x;
    else
        parent[x] = y;
    return true;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        parent[i] = i;
    
    int temp = 0;
    for(int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        if(!Union(x,y) && temp == 0)
            temp = i;
    }

    cout << temp;
}
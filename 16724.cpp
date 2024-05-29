#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int p[1000001];
bool vis[1000001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int find(int x){
    if(p[x] == x)
        return x;
    return p[x] = find(p[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b)
        return false;
    else if(a < b)
        p[b] = a;
    else
        p[a] = b;
    return true;
}

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    


}
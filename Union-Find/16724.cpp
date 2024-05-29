#include <bits/stdc++.h>
using namespace std;

char arr[1001][1001];
int parent[1000001];
bool vis[1000001];


int n,m;

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a == b)
        return;
    else if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
    return;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++)
            arr[i][j] = str[j];
    }
    
    for(int i=0; i<n*m; i++){
        parent[i] = i;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int nx = i;
            int ny = j;
            
            if(arr[i][j] == 'D')
              {nx++;}
            else if(arr[i][j] == 'U')
              {nx--;}
            else if(arr[i][j] == 'L')
              {ny--;}
            else if(arr[i][j] == 'R')
              {ny++;}
            
            Union(i*m+j, nx*m+ny);
        }
    }
    
    int result = 0;
    for(int i=0; i<n*m; i++){
        if(!vis[find(i)]){
            vis[find(i)] = true;
            result ++;
        }
    }
    
    cout << result;
}
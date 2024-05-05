#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> adj;
int parent[100001];

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

bool Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)
        return true;
    else if(x < y)
        parent[y] = x;
    else
        parent[x] = y;
    return false;
}

int main(){
    int house,road;
    cin >> house >> road;
    
    for(int i=0; i<house; i++)
        parent[i] = i;

    for(int i=0; i<road; i++){
        int x,y,z;
        cin >> x >> y >> z;
        adj.push_back({z,x,y});
    }

    sort(adj.begin(),adj.end());

    int cnt = 0;
    int sum = 0;
    for(auto nxt : adj){
        
        int cost,a,b;
        tie(cost,a,b) = nxt;
        
        if(Union(a,b))
            continue;
        cnt++;
        if(cnt == house - 1)
            break;
        sum+=cost;
    }

    cout << sum;
}
#include <bits/stdc++.h>
using namespace std;

int indegree[1010];
int construct_time[1010];
int dp[1010];

int n,m;

void topological_sort(vector <int> adj[1010]){
    queue <int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
            dp[i] = construct_time[i];
        }
            
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int nxt : adj[cur]){
            dp[nxt] = max(dp[nxt], dp[cur] + construct_time[nxt]);
            --indegree[nxt];
            if(indegree[nxt] == 0){
                q.push(nxt);
            }
        }
    }
}

void input(){
    int test_case;
    cin >> test_case;

    while(test_case--){

        vector <int> adj[1010];

        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> construct_time[i+1];
        }
        for(int i=0; i<m; i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            indegree[b]++;
        }

        int goal;
        cin >> goal;

        topological_sort(adj);
        cout << dp[goal] << '\n';

        for(int i=1; i<=n; i++){
            dp[i] = 0;
            indegree[i] = 0;
            construct_time[i] = 0;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}
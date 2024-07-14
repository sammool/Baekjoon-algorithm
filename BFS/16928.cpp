#include <bits/stdc++.h>
using namespace std;

int board[101];
bool vis[101];

int main(){
    int ladder,snake;
    cin >> ladder >> snake;

    for(int i=1; i<=100; i++)
        board[i] = i;
    for(int i=0; i<ladder+snake; i++){
        int from,to;
        cin >> from >> to;
        board[from] = to;
    }

    queue<pair<int,int>> q;
    q.push({1,0}); //1번에서 출발, 이동횟수 0
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int i=1; i<=6; i++){
            int nxt = cur.first + i;
            
            if(nxt == 100){   //100번 칸에 도착했을 때 
                cout << cur.second + 1;
                return 0;
            }
            else{
                if(board[nxt]){
                    nxt = board[nxt];
                }
                if(!vis[nxt]){
                    vis[nxt] = true;
                    q.push({nxt,cur.second+1});
                }
            }
        }
    }
    
}

// int location = 1;
//     int count = 0;

//     while(location<100){
//         count++;
//         int maxLocation = location;

//         for(int i=1; i<=6; i++){
//             int next = location + i;
//             if(next == 100){
//                 cout << count;
//                 return 0;
//             }
//             next = board[next];
//             if(vis[next])
//                 continue;
//             maxLocation = max(maxLocation, next);
           
//         }
//         location = maxLocation;
//         vis[location] = true;
        
//     }
   
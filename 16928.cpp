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
    int location = 1;
    int count = 0;

    while(location<100){
        count++;
        int maxLocation = location;

        for(int i=1; i<=6; i++){
            int next = location + i;
            if(next == 100){
                cout << count;
                return 0;
            }
            next = board[next];
            if(vis[next])
                continue;
            maxLocation = max(maxLocation, next);
           
        }
        location = maxLocation;
        vis[location] = true;
        
    }
   
}
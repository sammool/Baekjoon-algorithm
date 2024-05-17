#include <bits/stdc++.h>
using namespace std;

string str[10];
int arr[10][10];
int zero_cnt = 0;
vector<pair<int,int>> v;

void input(){
for(int i=0; i<9; i++){        
        cin >> str[i];
        for(int j=0; j<9; j++){
            arr[i][j] = str[i][j] - '0';
        }
    }
}

bool possible(int x, int y, int z){
    
    for(int i=0; i<9; i++){
        //가로 확인
        if(arr[x][i] == z)
            return false;
        
        //세로 확인
        if(arr[i][y] == z)
            return false;
    }
    
    //정사각형 확인
    int nx = x/3;
    int ny = y/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[nx*3 + i][ny*3+j] == z)
                return false;
        }
    }
    return true;
    
}

void backTraking(int k){
    if(k == zero_cnt){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++)
                cout << arr[i][j];
            cout << '\n';
        }

        exit(0);
    }
    int x = v[k].first;
    int y = v[k].second;

    for(int z=1; z<=9; z++){
        if(possible(x,y,z)){
            arr[x][y] = z;
            backTraking(k+1);
            arr[x][y] = 0;
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(arr[i][j] == 0){
                zero_cnt++;
                v.push_back({i,j});
            }
        }
    }
    backTraking(0);
}
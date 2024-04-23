// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int arr[129][129]; 
int white = 0; 
int blue = 0; 

void recursion(int x, int y, int k){
    bool isPaper = true; 
    int blueOrwhite = arr[x][y];
    for (int i = x; i < x + k; i++){
        for (int j = y; j < y + k; j++){
            if(arr[i][j] != blueOrwhite){
                isPaper = false; 
                break; 
            }
        }
    }
    if(!isPaper){ 
        recursion(x, y, k/2); 
        recursion(x+k/2, y, k/2); 
        recursion(x, y+k/2, k/2); 
        recursion(x+k/2, y+k/2, k/2); 
    }else{
        if(blueOrwhite == 1)
            blue++;
        else 
            white++;
    }    
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    recursion(0, 0, n);
    cout << white << '\n';
    cout << blue;
}

#include <bits/stdc++.h>
using namespace std;

int input[15];
int arr[7];
bool isUsed[15];
int n;
void func(int);

int main(){
    while(1){
        
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> input[i];
        func(1);
        cout << '\n';
        if(n == 0)
            break; 
    }
}
void func(int k){
    if(k == 7){
        for(int i=1; i<=6; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++){
        if(!isUsed[i]){
            if(input[i] > arr[k-1]){
                arr[k] = input[i];
                isUsed[i] = 1;
                func(k+1);
                isUsed[i] = 0;
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int arr[10];
int input[10];
bool isUsed[10];
int n,m;

void backTracking(int k){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    int tmp=-1;
    for(int i=0; i<n; i++){
        if(!isUsed[i] && tmp != input[i]){
            arr[k] = input[i];
            tmp = input[i];
            isUsed[i] = true;
            backTracking(k+1);
            isUsed[i] = false;
        }
    }
}

int main(){
    
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> input[i];
    sort(input,input+n);

    backTracking(0);
}
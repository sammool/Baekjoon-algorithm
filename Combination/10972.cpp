#include <bits/stdc++.h>
using namespace std;

int arr[10001];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    if(next_permutation(arr,arr+n)){
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
    }
      else
            cout << -1;

    return 0;
}
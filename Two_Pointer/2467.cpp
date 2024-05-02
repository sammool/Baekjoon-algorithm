#include <bits/stdc++.h>
using namespace std;
long arr[100001];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    
    int st = 0;
    int en = n-1;
    int result_left = arr[st];
    int result_right = arr[en];

    long min = abs(arr[en] + arr[st]);

    while(st<en){
        long result = arr[st]+arr[en];
        
        if(abs(result) < min){
            min = abs(arr[st]+arr[en]);
            result_left = arr[st];
            result_right = arr[en];
        }

        if(result > 0)
            en--;
        else if(result < 0)
            st++;
        else
            break;

    }

    cout << result_left <<" "<< result_right;
    
}
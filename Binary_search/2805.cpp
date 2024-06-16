#include <bits/stdc++.h>
using namespace std;

int tree[1000001];
int main() {
    int n,goal;
    cin >> n >> goal;
    
    int end = 0;
    for(int i=0; i<n; i++){
        cin >> tree[i];
        end = max(end,tree[i]);
    }
    
    int start = 0;
    
    int height = (start+end) / 2;
    
    while(start <= end){
        long long sum = 0;
        for(int i=0; i<n; i++){
            if(tree[i] < height)
                continue;
            sum += tree[i] - height;
        }
        
        if(sum < goal){
            end = height-1;
            height = (start+end) / 2;
        }
        else if(sum >= goal){
            start = height+1;
            height = (start+end) / 2;
        }
    }
    
    cout << height;
}
#include <bits/stdc++.h>
using namespace std;

int gate[100001];

int find(int x){
    if(gate[x] == x)
        return x;
    return gate[x] = find(gate[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        gate[a] = b;
    }
}

int main() {
    int G,F;
    cin >> G >> F;

    for(int i=0; i<=G; i++){
        gate[i] = i;
    }
    
    int *flight = new int[F];

    for(int i=0; i<F; i++){
        cin >> flight[i];
    }
    int result = 0;

    for(int i=0; i<F; i++){
        if(find(flight[i]) == 0)
            break;
        else{
            result++;
            Union(flight[i], find(flight[i])-1);
        }
    }

    cout << result;
    
}
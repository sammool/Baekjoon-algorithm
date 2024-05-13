#include <bits/stdc++.h>
using namespace std;

//nCr 구현 (5C3)

int n = 5;
int r = 3;
int arr[] = {1,2,3,4,5};

vector <int> v;

void print(vector<int> v){
    for(auto &element: v)
        cout << element << " ";
    cout << '\n';
}

void combination(int start, vector<int> v){
    if(v.size() == r){
        print(v);
        return;
    }

    for(int i = start; i<n; i++){
        v.push_back(arr[i]);
        combination(i+1,v);
        v.pop_back();
    }
    return;
}

int main(){
    combination(0,v);
    return 0;
}

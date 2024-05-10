#include <bits/stdc++.h>
using namespace std;

char arr[16];
char input[16];
int L,C;

void func(int);

int main(){
   
    cin >> L >> C;
    for(int i=1; i<=C; i++)
        cin >> input[i];
    sort(input+1,input+C+1);
    func(1);
    
}

void func(int k){
    int mo_cnt=0, ja_cnt=0;
    if(k == L+1){
        for(int i=1; i<=L; i++){
            if(arr[i]=='a' || arr[i] =='e'|| arr[i] =='i'|| arr[i] =='o'|| arr[i] =='u')
                mo_cnt++;
            else
                ja_cnt++;
        }
        
        if(mo_cnt <1 || ja_cnt <2)
            return;
        
        for(int i=1; i<=L; i++)
            cout << arr[i];
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=C; i++){
        if(arr[k-1]<input[i]){
            arr[k] = input[i];
            func(k+1);
        }
    }
}
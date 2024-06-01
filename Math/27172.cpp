#include <bits/stdc++.h>
using namespace std;

int score[1000001]; int card[1000001]; 
vector<int> number;

int main()
{ 
    int n; 
    cin >> n; 
    for(int i=0; i<n; i++){ 
        int x; 
        cin >> x; 
        number.push_back(x); 
        card[x] = 1; 
    }

for(int i = 0; i<n; i++){
    int temp = number[i];
    for(int j = temp*2; j<1000001; j+=temp){
        if(card[j]!=0){
            score[number[i]]++;
            score[j]--;
        }
    }
}

for(int i=0; i<n; i++){
    cout << score[number[i]] << " ";
}
}


#include <bits/stdc++.h>
using namespace std;

int alpa[26];
string word[11];

bool compare(int a, int b){
    return a>b;
}

int main() {
   int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> word[i];
        int pow = 1;
        for(int j=word[i].length()-1; j>=0; j--){
            alpa[word[i][j]-'A'] += pow;
            pow*=10;
        }
    }
    
    sort(alpa,alpa+26,compare);

    int sum=0;
    int x=9;
    for(int i=0; i<26; i++){
        sum+=alpa[i]*x;
        x--;
    }
    cout << sum;
}
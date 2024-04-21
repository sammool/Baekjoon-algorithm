#include <bits/stdc++.h>
using namespace std;

long dp_zero[41];
long dp_one[41];


int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    dp_zero[0] = 1;
    dp_zero[1] = 0;

    dp_one[0] = 0;
    dp_one[1] = 1;

    for(int j=2; j<=40; j++){
            dp_zero[j] = dp_zero[j-1] + dp_zero[j-2];
            dp_one[j] = dp_one[j-1] + dp_one[j-2];
        }

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int x;
        cin >> x;
        cout << dp_zero[x] << " " << dp_one[x] << '\n';
    }

}
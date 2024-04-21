#include <bits/stdc++.h>
using namespace std;

int person[1001];
int INF = 1001;

int main(){
    int n;
    cin >> n;

    fill(person,person+1001, INF);

    for(int i=0; i<n; i++)
        cin >> person[i];
    sort(person,person+1001);

    int time = 0;
    int result = 0;
    for(int i=0; i<n; i++){
        time+=person[i];
        result+=time;
    }

    cout << result;

}
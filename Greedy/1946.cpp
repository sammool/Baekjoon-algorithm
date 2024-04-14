#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;

    while(test--){                      //T
        
        vector<pair<int,int>> emp;
        
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            emp.push_back({x,y});
        }
        sort(emp.begin(),emp.end(),compare); //nlogn
    
        int min = 200000;
        int cnt=0;
        for(int i=0; i<n; i++){             //n
            if(emp[i].second < min){
                min = emp[i].second;
                cnt++;
            }
        }
        cout << cnt << '\n';

    }
}
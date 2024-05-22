#include <bits/stdc++.h>
using namespace std;

int A[1001];
int B[1001];
int a,b;
int t;
void input(){
    cin >> t;

    cin >> a;
    for(int i=0; i<a; i++){
        cin >> A[i];
    }
    cin >> b;
    for(int i=0; i<b; i++){
        cin >> B[i];
    }
}

int main(){
    input();
    vector<int> aSum;
    vector<int> bSum;
    
    for(int i=0; i<a; i++){
        long long sum = A[i];
        aSum.push_back(sum);
        for(int j=i+1; j<a;j++){
            sum+=A[j];
            aSum.push_back(sum);
        }
    }
    
    for(int i=0; i<b; i++){
        long long sum = B[i];
        bSum.push_back(sum);
        for(int j=i+1; j<b;j++){
            sum+=B[j];
            bSum.push_back(sum);
        }
    }
    
    sort(bSum.begin(),bSum.end());
    long long result = 0;
   for(int i=0; i<aSum.size(); i++){
       
       int target = t-aSum[i];
       int low = lower_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
       int up = upper_bound(bSum.begin(),bSum.end(), target) - bSum.begin();
       result += (up - low);
    }
   
   cout << result;
}
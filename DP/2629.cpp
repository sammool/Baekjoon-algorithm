#include <bits/stdc++.h>
using namespace std;

bool dp[31][40001];
int weight[31];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>weight[i];


    for(int i=1;i<=n;i++){
        dp[i][weight[i]] = true;
        for(int j=1; j<=40000; j++){
            //같은 쪽에 추를 올리는 경우
            if(j-weight[i]>=0 && dp[i-1][j-weight[i]]){
                dp[i][j] = true;
            }
            //추를 올리지 않거나 반대쪽에 올리는 경우
            if(dp[i-1][j]){
                dp[i][j] = true;
                dp[i][abs(j-weight[i])] = true;
            }

        }
    }
    int bead_num;
    cin>>bead_num;
    for(int i=0; i<bead_num; i++)
    {
        int x;
        cin >> x;
        if(dp[n][x])
            cout << "Y" <<" ";
        else
            cout << "N" <<" ";
    }
}

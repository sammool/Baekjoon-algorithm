#include <bits/stdc++.h>
using namespace std;

int arr[51][51];
int INF = 1000000000;

int n,m;

int measure_dist(vector<pair<int,int>> &v){
    int dist = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int min_dist = INF;
            if(arr[i][j] == 1){
                for(auto e:v){
                    min_dist = min(min_dist, (abs(e.first - i) + abs(e.second - j)));
                }
                dist+=min_dist;
            }
        }
    }
    return dist;
}

int main()
{
    
    cin >> n >> m;

    vector<pair<int,int>> chi;
    int chi_cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                chi.push_back({i,j});
                chi_cnt++;
            }
        }
    }
    //조합을 위한 comb vector
    vector<int> comb;
    for(int i=0; i<chi_cnt-m; i++)
        comb.push_back(0);
    for(int i=0; i<m; i++)
        comb.push_back(1);

    int size = comb.size();
    int result = INF;

    do{
        //거리 계산용 치킨집 좌표
        vector<pair<int,int>> chi_max;

        for(int i=0; i<size; i++){
            if(comb[i] == 1)
                chi_max.push_back(chi[i]);
        }

        result = min(result,measure_dist(chi_max));

    }while(next_permutation(comb.begin(), comb.end()));

    cout << result;
    
}
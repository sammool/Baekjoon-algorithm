#include <bits/stdc++.h>
using namespace std;

int arr[5001];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+n);
    
    vector<pair<int,int>> v;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            v.push_back({arr[i],arr[j]});
        }
    }
    
    long long min = 9e10;
    
    int result[3];
    
    for(int i=0; i<v.size(); i++){
        long long value = v[i].first + v[i].second;
        int idx = lower_bound(arr,arr+n, -value) - arr;
        
        for(int j = idx-2; j<idx+2; j++)
        {
            if(j<0||j>=n||arr[j]==v[i].first||arr[j] == v[i].second)
                continue;

            long long three = abs(value+arr[j]);
            if(three < min){
                result[0] = v[i].first;
                result[1] = v[i].second;
                result[2] = arr[j];
                min = three;
            }
        }
    }
    sort(result,result+3);
    for(int i=0; i<3; i++)
        cout << result[i] << " ";
    
}

// //투포인터 코드
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
    
//     vector<int> arr(n);
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
    
//     sort(arr.begin(), arr.end());
    
//     long long min_diff = LLONG_MAX;
//     int result[3];

//     for(int i = 0; i < n - 2; i++){
//         int left = i + 1;
//         int right = n - 1;

//         while(left < right){
//             long long sum = (long long)arr[i] + arr[left] + arr[right];
            
//             if(abs(sum) < min_diff){
//                 min_diff = abs(sum);
//                 result[0] = arr[i];
//                 result[1] = arr[left];
//                 result[2] = arr[right];
//             }

//             // 이 부분에서 합이 0에 가까워지도록 left와 right를 이동시킵니다.
//             if(sum < 0){
//                 left++;
//             } else {
//                 right--;
//             }
//         }
//     }

//     for(int i = 0; i < 3; i++){
//         cout << result[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
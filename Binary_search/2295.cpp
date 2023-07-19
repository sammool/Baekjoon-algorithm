#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A[1001];


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector <int> two;

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];
    sort(A,A+n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            two.push_back(A[i]+A[j]);
    }
    sort(two.begin(), two.end());

    int max=0;
    int size = two.size();
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j < i ; j++)
        {
            if (binary_search(two.begin(),two.end(),A[i]-A[j]))
            { 
                cout << A[i];
                return 0;
            }
        }
    }
}
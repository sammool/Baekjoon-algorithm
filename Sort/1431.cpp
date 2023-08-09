#include <iostream>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b)
{
    int a_len = a.length(), b_len = b.length();
    if(a_len != b_len)
        return a_len<b_len;
    
    else if(a_len == b_len)
    {
        int a_sum=0, b_sum=0;
        for(int i=0; i<b_len; i++)
        {
            if(a[i] >= '0' && a[i] <= '9')
               a_sum+=a[i] - '0';
            if(b[i] >= '0' && b[i] <= '9')
               b_sum+=b[i] - '0';
        }
        if(a_sum == b_sum)
        {
            return a<b;
        }
        return a_sum < b_sum;
    }
}

int main()
{
    string arr[51];

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string str;
        cin >> str;
        arr[i] = str;
    }

    sort(arr, arr+n, compare);

    for(int i=0; i<n; i++)
        cout << arr[i] << '\n';
}
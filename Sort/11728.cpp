#include <iostream>
using namespace std;

int a[1000001];
int b[1000001];
int c[2000005];
    

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;

    for(int i=0; i< n; i++)
        cin >> a[i];
    for(int i=0; i< m; i++)
        cin >> b[i];

    int a_idx=0, b_idx=0;
    int len = n+m;
    
    for(int i=0; i<len; i++)
    {
        if(a_idx == n)
            c[i] = b[b_idx++];
        
        else if(b_idx == m)
            c[i] = a[a_idx++];
        
        else if(a[a_idx] <= b[b_idx])
            c[i] = a[a_idx++];
        
        else if(b[b_idx] < a[a_idx])
            c[i] = b[b_idx++];
    }

    for(int i=0; i<len; i++)
        cout << c[i] << " ";
}
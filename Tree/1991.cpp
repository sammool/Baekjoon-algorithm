#include <bits/stdc++.h>
using namespace std;

int lc[30], rc[30], par[30];

void preorder(int root)
{
    cout << char(root +'A' -1);
    if(lc[root] != ('.' - 'A' +1)) 
        preorder(lc[root]);
    if(rc[root] != ('.' - 'A' +1))
        preorder(rc[root]);
}

void inorder(int root)
{
    if(lc[root] != ('.' - 'A' +1)) 
        inorder(lc[root]);
    cout << char(root +'A' -1);
    if(rc[root] != ('.' - 'A' +1))
        inorder(rc[root]);
}

void postorder(int root)
{
    if(lc[root] != ('.' - 'A' +1)) 
        postorder(lc[root]);
    if(rc[root] != ('.' - 'A' +1))
        postorder(rc[root]);
    cout << char(root +'A' -1);
}

int main()
{

    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        char Par,Lc,Rc;
        cin >> Par >> Lc >> Rc;
        lc[Par-'A'+1] = Lc - 'A' +1;
        rc[Par-'A'+1] = Rc - 'A' +1;
    }
    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
}
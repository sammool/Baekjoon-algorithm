#include <bits/stdc++.h>
using namespace std;

int Index[100001];
int postorder[100001];
int inorder[100001];

void getPreorder(int inStart, int inEnd, int postStart, int postEnd){
    //종료시점 Todo
    if(inStart > inEnd || postStart > postEnd)
        return;

    int root = postorder[postEnd];
    int rootIndex = Index[root];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;

    //root출력
    cout << root << " ";

    //죄측
    getPreorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1 ); 
    getPreorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);

    //우측
}

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> inorder[i];
        Index[inorder[i]] = i;
    }
    for(int i=1; i<=n; i++){
        cin >> postorder[i];
    }

    getPreorder(1,n,1,n);
}
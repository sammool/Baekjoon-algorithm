#include <iostream>
#include <vector>
using namespace std;

vector <int> area;

void query1()
{
    int x;
    cin >> x;
    if(area[x-1] == -1)
        area[x-1] = x;
    else
        area[x-1] = -1;
}
void query2(vector<int>::iterator &itr)
{
    int x;
    cin >> x;
    for(int i=0; i<x; i++)
    {
         if(itr == area.end())
            itr = area.begin();
        itr++;
    }
}
void query3(vector<int>::iterator &itr, int n)
{
    auto tmp = itr;
    int move=0;
   while(*itr == -1)
   {
        if(itr == area.end())
            itr = area.begin();
        itr++;
        move++;                
   }
//    if(move >= n)
//         move = -1;
  
   cout << move << '\n';
   itr = tmp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        if(x==0)
            area.push_back(-1);
        else    
            area.push_back(i+1);
    }

    auto itr= area.begin();

    for(int i=0; i<q; i++)
    {
        int number;
        cin >> number;
        if(number == 1)
            query1();
        else if(number == 2)
            query2(itr);
        else
            query3(itr, n);
    }
    return 0;

}
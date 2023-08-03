// #include <iostream>
// #include <vector>
// using namespace std;

// vector <int> area;

// void query1()
// {
//     int x;
//     cin >> x;
//     if(area[x-1] == -1)
//         area[x-1] = x;
//     else
//         area[x-1] = -1;
// }
// void query2(vector<int>::iterator &itr)
// {
//     int x;
//     cin >> x;
//     for(int i=0; i<x; i++)
//     {
//          if(itr == area.end())
//             itr = area.begin();
//         itr++;
//     }
// }
// void query3(vector<int>::iterator &itr, int n)
// {
//     auto tmp = itr;
//     int move=0;
   
//    while(*itr == -1)
//    {
//         itr++;
//         if(itr == area.end())
//             itr = area.begin();
//         move++;      
        
//         if(move >= n)
//         { 
//             move = -1;
//             break;
//         }          
//    }
  
//    cout << move << '\n';
//    itr = tmp;
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n,q;
//     cin >> n >> q;
//     for(int i=0; i<n; i++)
//     {
//         int x;
//         cin >> x;
//         if(x==0)
//             area.push_back(-1);
//         else    
//             area.push_back(i+1);
//     }

//     auto itr= area.begin();

//     for(int i=0; i<q; i++)
//     {
//         int number;
//         cin >> number;
//         if(number == 1)
//             query1();
//         else if(number == 2)
//             query2(itr);
//         else
//             query3(itr, n);
//     }
//     return 0;

// }
#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    set <int> place;
    int n,k;
    int loc = 1;
    cin >> n >> k;

    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        if(x==1)
            place.insert(i);
    }

    for(int i=0; i<k; i++)
    {
        int x;
        cin >> x;
        switch(x)
        {
            case 1:
                int x1;
                cin >> x1;
                if(place.find(x1) == place.end())
                    place.insert(x1);
                else
                    place.erase(x1);
                break;

            case 2:
                int x2;
                cin >> x2;
                loc += x2;
               if(loc > x2)
                    loc -= n;
                break;
            
            case 3:

                if(place.empty())
                    cout << -1 << '\n';

                else
                {
                    auto x3 = place.lower_bound(loc);
                    if(x3 != place.end())
                        cout << *x3 - loc << '\n';
                    else
                        cout << n - loc + *place.begin() << '\n';
                }
        }
    }
    
}
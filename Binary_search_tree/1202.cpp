#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin >> n >> k;
	
	pair<int, int> v [300001];
	multiset <int> bag;
	
	
	for(int i=0; i<n; i++)
		cin >> v[i].second >> v[i].first;
	
	for(int i=0; i<k; i++)
	{	
       int x;
	   cin >> x;
	   bag.insert(x); 
	}
	
	sort(v, v+n);
	
	for(int i=n-1; i>=0; i--)
	{
		for(auto j=bag.begin(); j!=bag.end(); j++)
		{
			if(v[i].second <= *j && v[i].first >[bag[j]])
			{
				[bag[j]] = v[i].first;
				break;
			}
		}
	}
	int sum = 0;
	for(auto i = res.begin(); i!=res.end(); i++)
		sum += i->second;
	cout << sum;
		
}
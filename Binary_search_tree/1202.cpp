#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	
	vector <pair<int, int>> v;
	vector <int> bag;
	map <int,int> res;
	
	for(int i=0; i<n; i++)
	{
        int x,y;
		cin >> x >> y;
        v.push_back(make_pair(x,y));
	}
	
	for(int i=0; i<k; i++)
	{	
        int x;
		cin >> x;
        bag.push_back(x);
		res[bag[i]] = 0;
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<k; j++)
		{
			if(v[i].first <= bag[j])
			{
				res[bag[j]] = max(res[bag[j]], v[i].second);
				break;
			}
		}
	}
	int sum = 0;
	for(auto i = res.begin(); i!=res.end(); i++)
		sum += i->second;
	cout << sum;
		
}
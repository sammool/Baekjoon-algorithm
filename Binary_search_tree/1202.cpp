#include <iostream>
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
	
	long long sum=0;
	for(int i=n-1; i>=0; i--)
	{
		auto it = bag.lower_bound(v[i].second); // O(log N) 이분탐색 lower_bound는 O(N)
		if(it == bag.end())
			continue;
		sum+=v[i].first;
		bag.erase(it);
	}

	cout << sum;
		
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b)
{
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unordered_map <string, int> h;
	int n, l;
	cin >> n >> l;
	
	for(int i=0; i<l; i++)
	{
		string str;
		cin >> str;
		if(h.find(str) != h.end())
			h.erase(str);
		h[str]=i;
	}
	vector <pair<string, int>> v;
	for(auto &i : h)
		v.push_back(i);
	
	sort(v.begin(), v.end(), compare);
	
	int _min = min(n,(int)v.size());
	
	for(int i=0; i<_min; i++)
		cout << v[i].first << '\n';
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string str;
	vector <int> v2(26);
	cin >> str;
	
	for(int i=0; i<str.size(); i++)
	{
		v2[str[i]-97]++;
	}
	
	for(auto &ele: v2)
		cout << ele << ' ';
}

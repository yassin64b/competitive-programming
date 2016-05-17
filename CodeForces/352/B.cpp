#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	
	if(n > 26)
	{
		cout << -1 << endl;
		return 0;
	}

	vector<int> v(26, 0);

	for(int i = 0; i < n; ++i)
		v[s[i]-'a']++;

	int sum = 0;
	for(int i = 0; i < 26; ++i)
	{
		if(v[i] > 1)
			sum += v[i]-1;
	}

	cout << sum << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <utility>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;

	char point = 'a';
	int cnt = 0;
	for(int i = 0; i < (int)s.size(); ++i)
	{
		
		int tmp = abs(s[i] - point);
		cnt += min(tmp, 26-tmp);
		point = s[i];
	}
	cout << cnt << endl;

	return 0;
}
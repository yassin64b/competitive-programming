#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int N = s.size();
	int cnt = 0;
	for(int i = 0; i < N; ++i)
	{
		if(i % 2 == 0 && s[i] == 'p')
			--cnt;
		else if(i % 2 == 1 && s[i] == 'g')
			++cnt;
	}
	cout << cnt << endl;
	return 0;
}
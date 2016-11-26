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
	int n;
	string s;
	cin >> n >> s;

	int ans1 = 0, ans2 = 0;

	bool inbrackets = false;
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == '(')
			inbrackets = true;
		else if(s[i] == ')')
			inbrackets = false;
		else if(s[i] == '_')
			continue;
		else if(!inbrackets)
		{
			int cnt = 1;
			++i;
			while(i < n && s[i] != '_' && s[i] != '(' && s[i] != ')')
				++cnt, ++i;
			--i;
			ans1 = max(ans1, cnt);
		}
		else if(inbrackets)
		{
			++ans2;
			while(i < n && s[i] != '_' && s[i] != '(' && s[i] != ')')
				++i;
			--i;
		}
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
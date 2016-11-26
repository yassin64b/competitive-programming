#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	string s;
	cin >> s;

	for(int i = 0; i < (int)s.size()-25; ++i)
	{
		set<char> m;
		for(char c = 'A'; c <= 'Z'; ++c)
			m.insert(c);

		bool flag = true;
		for(int j = 0; flag && j < 26; ++j)
		{
			int cnt = -1;
			if(s[i+j] != '?')
				cnt = m.erase(s[i+j]);
			if(cnt == 0)
				flag = false;
		}

		if(flag)
		{
			int j = 0;
			for(const char& c: m)
			{
				//cout << i << " " << j << endl;
				while(s[i+j] != '?')
					++j;
				s[i+j] = c;
			}

			for(int j = 0; j < (int)s.size(); ++j)
				if(s[j] == '?') s[j] = 'A';
			cout << s << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
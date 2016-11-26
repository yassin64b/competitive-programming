#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
using namespace std;

const int LEN = 1048576;

int main()
{
	int* cnt = new int[LEN];
	fill(cnt, cnt+LEN, 0);
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t)
	{
		char c;
		cin >> c;
		if(c == '+' || c == '-')
		{
			string s;
			cin >> s;
			for(int i = 0; i < (int)s.size(); ++i)
			{
				s[i] = ((s[i]-'0') % 2) + '0';
			}

			unsigned long pat = 0;
			bitset<20> b(s);
			pat = b.to_ulong();
			cnt[pat] += (c == '+' ? 1 : -1);
		}
		else
		{
			string s;
			cin >> s;
			bitset<20> b(s);
			unsigned long pat = b.to_ulong();
			cout << cnt[pat] << endl;
		}
	}
	delete[] cnt;
	return 0;
}
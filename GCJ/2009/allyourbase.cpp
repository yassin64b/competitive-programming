#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

int main()
{
	int T;

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		char s[70];
		scanf("%s", s);

		int value[128]{0};
		int base = 0;
		for(int i = 0; i < (int)strlen(s); ++i)
		{
			if(value[s[i]] == 0)
				value[s[i]] = ++base;
		}
		if(base == 1) ++base;

		long long res = 0;

		for(int i = 0; i < (int)strlen(s); ++i)
		{
			long long cur = value[s[i]];
			if(cur == 2)
				cur = 0;
			else if(cur != 1)
				--cur;

			res = res * base + cur;
		}
		printf("Case #%d: %lld\n", t, res);
	}
}
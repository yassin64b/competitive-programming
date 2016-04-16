#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

int main()
{
	int T, count, i;
	char pan[110];
	bool happy;

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		scanf("%s", pan);
		count = 0;
		
		for(int i = 1; i < (int)strlen(pan); ++i)
		{
			if(pan[i-1] != pan[i])
				++count;
		}
		if(pan[(int)strlen(pan)-1] == '-')
			++count;

		printf("Case #%d: %d\n", t, count);

	}
	return 0;
}
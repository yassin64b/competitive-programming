#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

int main()
{
	int T, N, i;
	long long val, tmp;

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ", t);

		char s[20] = "0000000000";
		scanf("%d", &N);
		if(N == 0)
		{
			printf("INSOMNIA\n");
			continue;
		}

		val = N; i = 0;
		while(strcmp(s, "1111111111"))
		{
			val = ++i * N;
			long long tmp = val;

			while(tmp > 0)
			{
				s[tmp % 10] = '1';
				tmp /= 10;
			}
		}
		printf("%d\n", val);

	}
	return 0;
}
#include <cstdio>

int main()
{
	int T, N, wall, high, low, cur;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for(int i = 1; i <= T; ++i)
	{
		scanf("%d", &N);
		high = 0; low = 0;

		if(N != 0) scanf("%d", &cur);

		for(int j = 1; j < N; ++j)
		{
			scanf("%d", &wall);

			if(cur < wall)
				++high;
			else if(cur > wall)
				++low;

			cur = wall;
		}	
		printf("Case %d: %d %d\n", i, high, low);
	}
	return 0;
}
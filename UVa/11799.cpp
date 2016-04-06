#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int T, N, max, cur;

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		scanf("%d", &N);
		max = 0;
		for(int n = 0; n < N; ++n)
		{
			scanf("%d", &cur);
			if(cur > max)
				max = cur;
		}

		printf("Case %d: %d\n", t, max);
	} 
	return 0;
}

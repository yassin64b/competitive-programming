#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);

	int T, N, cur, p1, p2;

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		scanf("%d", &N);
		p1 = 0; p2 = 0;

		for(int n = 1; n <= N; ++n)
		{
			scanf("%d", &cur);
			p1 += (cur / 30 + 1) * 10;
			p2 += (cur / 60 + 1) * 15;
		}

		printf("Case %d: ", t);

		if(p1 < p2)
			printf("Mile %d\n", p1);
		else if(p1 > p2)
			printf("Juice %d\n", p2);
		else
			printf("Mile Juice %d\n", p1);
	}
	return 0;
}
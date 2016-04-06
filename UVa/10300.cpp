#include <cstdio>
#include <cstring>

int main()
{
	freopen("input.txt", "r", stdin);

	int n, f;
	long long size, numa, env, sum;

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		sum = 0;
		scanf("%d", &f);

		for(int j = 0; j < f; ++j)
		{
			scanf("%lld %lld %lld", &size, &numa, &env);
			sum += size * env;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
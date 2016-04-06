#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(n < 0 && n % 2 != 0)
			printf("Overflow!\n");
		else if(n > 13)
			printf("Overflow!\n");
		else if(n < 8)
			printf("Underflow!\n");
		else
		{
			long long f = n;
			while(--n)
				f *= n;

			printf("%lld\n", f);
		}
	}
	return 0;
}
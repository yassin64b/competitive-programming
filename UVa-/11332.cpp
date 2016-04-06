#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);
	int n, sum;

	while(scanf("%d", &n) != EOF && n)
	{
		while(n > 9)
		{
			sum = 0;
			while(n != 0)
			{
				sum += n % 10;
				n /= 10;
			}
			n = sum;
		}
		printf("%d\n", n);
	}
}
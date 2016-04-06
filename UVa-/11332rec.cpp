#include <cstdio>

int process(int n)
{
	int sum = 0;
	while(n != 0)
	{
		sum += n%10;
		n /= 10;
	}
	return (sum > 9 ? process(sum) : sum);
}
int main()
{
	freopen("input.txt", "r", stdin);
	int n, sum;

	while(scanf("%d", &n) != EOF && n)
	{
		n = process(n);
		printf("%d\n", n);
	}
}
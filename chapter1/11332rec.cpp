#include <cstdio>

int process(int n)
{
	int sum = 0;
	while(n != 0)
	{
		sum += n%10;
		n /= 10;
	}
	if(sum > 9)
		return process(sum);
	else 
		return sum;
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
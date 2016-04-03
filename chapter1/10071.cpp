#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);

	int v, t;
	while(scanf("%d %d", &v, &t) != EOF)
		printf("%d\n", v*2*t);
	return 0;
}
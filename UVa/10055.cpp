#include <cstdio>
#include <cmath>
#include <cstdlib>

int main()
{
	freopen("input.txt", "r", stdin);

	long l, r;
	while(scanf("%ld %ld", &l, &r) != EOF)
		printf("%ld\n", (l < r) ? r-l : l-r);

	return 0;
}
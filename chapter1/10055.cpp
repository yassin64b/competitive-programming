#include <cstdio>
#include <cmath>
#include <cstdlib>

int main()
{
	freopen("input.txt", "r", stdin);

	unsigned int l, r;
	while(scanf("%u %u", &l, &r) != EOF)
		printf("%u\n", (l < r) ? r-l : l-r);

	return 0;
}
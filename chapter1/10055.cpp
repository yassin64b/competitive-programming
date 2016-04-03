#include <cstdio>
#include <cmath>

int main()
{
	std::freopen("input.txt", "r", stdin);

	long l, r;
	while(scanf("%ld %ld", &l, &r) != EOF)
		printf("%ld\n", (long)std::round(std::abs(r-l)));

	return 0;
}
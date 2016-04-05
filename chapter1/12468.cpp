#include <cstdio>
#include <algorithm>
#include <cmath>

int main()
{
	freopen("input.txt", "r", stdin);

	int a, b, s;

	while(scanf("%d %d", &a, &b) != EOF && (a != -1 || b != -1))
	{
		s = std::abs(b-a);
		printf("%d\n", std::min({s, 100-s}));
		//alternative:		(s > 50 ? 100 - s : s);
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <cmath>

int main()
{
	freopen("input.txt", "r", stdin);

	int a, b;

	while(scanf("%d %d", &a, &b) != EOF && (a != -1 || b != -1))
	{
		printf("%d\n", std::min({std::abs(b-a), 100-std::abs(b-a)}));
	}
	return 0;
}
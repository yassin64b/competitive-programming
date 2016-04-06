#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 4000000

vector<int> val(SIZE, 0);

int single(int n)
{
	if (n == 1)
		return 1;

	if (n < SIZE && val[(int)n] != 0)
		return val[(int)n];

	int res = 1 + single(((n % 2 == 0) ? (n / 2) : (3 * n + 1)));

	if (n < SIZE)
		val[(int)n] = res;

	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i, j, maxv, low, up;

	while (scanf("%lld %lld", &i, &j) != EOF)
	{
		maxv = 0;

		if (i > j)
			low = j, up = i;
		else
			low = i, up = j;

		for (int t = low; t <= up; ++t)
			maxv = std::max(maxv, single(t));

		printf("%lld %lld %lld\n", i, j, maxv);
	}
	return 0;
}
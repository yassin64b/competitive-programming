#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

#define SIZE 4000000

vector<long long> val(SIZE, 0);
long long cycle, maxv, low, up;

long long single(long long t)
{
	if (t == 1)
		return 1;

	if (t < SIZE && val[t] != 0)
		return val[t];

	long long res = 1 + single((t % 2 == 0 ? t / 2 : 3 * t + 1));

	if(t < SIZE)
		val[t] = res;

	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	long long i,j;

	while (scanf("%lld %lld", &i, &j) != EOF)
	{
		maxv = 0;

		if (i > j)
			low = j, up = i;
		else
			low = i, up = j;

		for (long long t = low; t <= up; ++t)
		{
			cycle = single(t);

			if (cycle > maxv)
				maxv = cycle;
		}

		printf("%lld %lld %lld\n", i, j, maxv);
	}
	return 0;
}
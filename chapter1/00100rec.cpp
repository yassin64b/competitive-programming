#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

#define SIZE 4000000

vector<int> val(SIZE, 0);
int i, j, cycle, maxv, res, low, up;

int single(int t)
{
	if (t == 1)
		return 1;

	if (t < SIZE && val[t] == 0) val[t] = single((t % 2 == 0 ? t / 2 : 3 * t + 1)) + 1;

	return t < SIZE ? val[t] : single((t % 2 == 0 ? t / 2 : 3 * t + 1)) + 1;
}

void solve()
{
	for (int t = low; t <= up; ++t)
	{
		cycle = single(t);

		if (cycle > maxv)
			maxv = cycle;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	while (scanf("%d %d", &i, &j) != EOF)
	{
		maxv = 0;

		if (i > j)
			low = j, up = i;
		else
			low = i, up = j;

		solve();

		printf("%d %d %d\n", i, j, maxv);
	}
	return 0;
}
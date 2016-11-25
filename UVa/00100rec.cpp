#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 4000000

vector<int> memo(SIZE, 0);

int cycleLength(long long n)
{
    if(n < 1) //overflow
        return 0;
    if (n == 1)
        return 1;

    if (n < SIZE && memo[n] != 0)
        return memo[n];

    int res = 1 + cycleLength(n % 2 == 0 ? n / 2 : 3 * n + 1);

    if (n < SIZE)
        memo[n] = res;

    return res;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int i, j, maxv, low, up;

	while (scanf("%d %d", &i, &j) != EOF)
	{
		maxv = 0;

		if (i > j)
			low = j, up = i;
		else
			low = i, up = j;

		for (int t = low; t <= up; ++t)
			maxv = std::max(maxv, cycleLength(t));

		printf("%d %d %d\n", i, j, maxv);
	}
	return 0;
}
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);

	int i, j, cycle, max, res, low, up;

	while(scanf("%d %d", &i, &j) != EOF)
	{
		max = 0;

		if(i > j)
			low = j, up = i;
		else
			low = i, up = j;

		for(int t = low; t <= up; ++t)
		{
			cycle = 1, res = t;
			while(res != 1)
			{
				res = res%2 == 0 ? res/2 : 3*res+1;
				++cycle;
			}
			if(cycle > max)
				max = cycle;
		}
		printf("%d %d %d\n", i, j, max);
	}
	
}
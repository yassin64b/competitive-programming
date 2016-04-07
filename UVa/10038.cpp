#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);

	int n, val[3010], diff[3010];
	bool flag;

	while(scanf("%d", &n) != EOF)
	{
		flag = true;

		for(int i = 0; i < n; ++i)
			scanf("%d", val+i);

		for(int i = 0; i < n-1; ++i)
			diff[i] = abs(val[i] - val[i+1]);

		sort(diff, diff + n-1);

		for(int i = 0; flag && i < n-1; ++i)
		{
			if(diff[i] != i+1)
				flag = false;
		}

		if(flag)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}

	return 0;
}
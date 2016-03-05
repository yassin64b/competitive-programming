#include <cstdio>


using namespace std;

int main()
{
	freopen("11727.txt","r",stdin);

	int T;
	int x[3];

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		scanf("%d %d %d", &x[0], &x[1], &x[2]);
		int res;

		if(x[0] > x[1])
		{
			if(x[0] > x[2])
			{
				res = x[1] < x[2] ? x[2] : x[1];
			}
			else
			{
				res = x[0];
			}
		}
		else if(x[0] < x[1])
		{
			if(x[0] < x[2])
			{
				res = x[1] > x[2] ? x[2] : x[1];
			}
			else
			{
				res = x[0];
			}
		}
		else
			res = x[0];


		printf("Case %d: %d\n", t, res);

	}
}
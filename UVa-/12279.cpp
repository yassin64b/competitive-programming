#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);

	int N, x, res, T = 0;

	while(scanf("%d", &N) != EOF)
	{
		++T;

		res = 0;
		for(int n = 1; n <= N; ++n)
		{
			scanf("%d", &x);

			res += x == 0 ? -1 : 1;
		}

		if(N != 0) printf("Case %d: %d\n", T, res);
	}

	
}
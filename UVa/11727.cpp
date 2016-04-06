#include <cstdio>
#include <algorithm>

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

		sort(x, x+3);

		printf("Case %d: %d\n", t, x[1]);

	}
}
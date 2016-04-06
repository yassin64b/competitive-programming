#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int T, n, m;

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		scanf("%d %d", &n, &m);

		int res = ceil( (n-2.)/3.)* ceil((m-2.)/3.);
		printf("%d\n", res);
	}
}
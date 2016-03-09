#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int T, N, l, r, tmp;

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		r = 0, l = 1000;

		scanf("%d", &N);
		for(int n = 0; n < N; ++n)
		{
			scanf("%d", &tmp);
			if(tmp > r) r = tmp;
			if(tmp < l) l = tmp;
		}

		printf("%d\n", (r-l)*2);
	}

}
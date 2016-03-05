#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int N, B, H, W, p, a, optVal = -1;

	while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF)
	{
		optVal = -1;

		for(int h = 0; h < H; ++h)
		{
			scanf("%d", &p);

			for(int w = 0; w < W; ++w)
			{
				scanf("%d", &a);

				if(a < N) continue;

				int tmp = p * N;

				if((tmp < optVal || optVal == -1) && tmp < B )
					optVal = tmp;

			}
			
		}
		optVal == -1 ? printf("stay home\n") : printf("%d\n", optVal);
	}

	
	return 0;
}
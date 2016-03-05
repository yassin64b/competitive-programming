#include <cstdio>

using namespace std;

int main()
{
	//freopen("11498.txt", "r", stdin);

	int K;
	

	int N, M, x, y;
	
	
	while(scanf("%d", &K) != -1)
	{
		scanf("%d %d", &N, &M);
		for(int k = 0; k < K; ++k)
		{
			scanf("%d %d", &x, &y);

			if(x == N || y == M)
				printf("divisa\n");
			else if(x < N)
				y < M ? printf("SO\n") : printf("NO\n");
			else if(x > N)
				y < M ? printf("SE\n") : printf("NE\n");

		}
	}

	return 0;
}
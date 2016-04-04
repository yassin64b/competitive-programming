#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);
	int B, N, R[22], D, C, V;

	while(scanf("%d %d", &B, &N) != EOF && B && N)
	{
		bool flag = true;

		for(int i = 0; i < B; ++i)
			scanf("%d", R+i);

		for(int i = 0; i < N; ++i)
		{
			scanf("%d %d %d", &D, &C, &V);
			R[D-1] -= V;
			R[C-1] += V;
		}

		for(int i = 0; i < B && flag; ++i)
			if(R[i] < 0) flag = false;

		flag == true ? printf("S\n") : printf("N\n");
	}
	return 0;
}
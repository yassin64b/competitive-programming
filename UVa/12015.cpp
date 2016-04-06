#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);

	char s[11][110];
	int N, max, V[11];

	scanf("%d", &N);

	for(int i = 1; i <= N; ++i)
	{
		max = 0;

		for(int j = 0; j < 10; ++j)
		{
			scanf("%s %d", s[j], V+j);
			
			if(V[j] > max) 
				max = V[j];
		}
		
		printf("Case #%d:\n", i);
		for(int j = 0; j < 10; ++j)
			if(V[j] == max)
				printf("%s\n", s[j]);
	}
	return 0;
}
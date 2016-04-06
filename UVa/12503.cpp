#include <cstdio>
#include <cstring>

int main()
{
	freopen("input.txt", "r", stdin);

	int T, N, pos, tmp, move[102];
	char in[40];

	scanf("%d", &T);

	for(int t = 0; t < T; ++t)
	{
		pos = 0;
		scanf("%d", &N);

		for(int n = 1; n <= N; ++n)
		{
			scanf("%s", in);
			if(!strcmp(in, "LEFT"))
				move[n] = -1;
			else if(!strcmp(in, "RIGHT"))
				move[n] = 1;
			else
			{
				scanf("%s %d", in, &tmp);
				move[n] = move[tmp];
			}
			pos += move[n];
		}
		printf("%d\n", pos);
	}
	return 0;
}
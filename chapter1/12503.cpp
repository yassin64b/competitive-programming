#include <cstdio>
#include <cstring>

int main()
{
	freopen("input.txt", "r", stdin);

	int T, N, pos, index, same[101];
	char in[101][40];

	scanf("%d", &T);

	for(int t = 0; t < T; ++t)
	{
		pos = 0;
		memset(same, 0, 101);

		scanf("%d", &N);

		for(int n = 0; n < N; ++n)
		{
			index = n;
			scanf("%s", in[index]);

			if(!strcmp(in[index], "SAME"))
			{
				scanf("%s %d", in[101], &index);
				same[n] = --index;
			}	
			
			while(!strcmp(in[index], "SAME"))
				index = same[index];

			if(!strcmp(in[index], "LEFT"))
				--pos;
			else if(!strcmp(in[index], "RIGHT"))
				++pos;
		}
		printf("%d\n", pos);
	}
	return 0;
}
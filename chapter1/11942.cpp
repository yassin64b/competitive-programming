#include <cstdio>


int main()
{
	freopen("input.txt", "r", stdin);
	int N, last, cur, order;

	scanf("%d", &N);
	printf("Lumberjacks:\n");

	for(int i = 0; i < N; ++i)
	{
		scanf("%d %d", &last, &cur);

		if(last < cur) 
			order = 1;
		else if(last > cur)
			order = 2;
		else
			order = 0;

		for(int j = 2; j < 10; ++j)
		{
			scanf("%d", &cur);
			
			if((order == 1 && last >= cur) || (order == 2 && last <= cur))
				order = 0;

			last = cur;
		}
		order ? printf("Ordered\n") : printf("Unordered\n");
	}

	return 0;
}
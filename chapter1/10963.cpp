#include <cstdio>
#include <cstring>

int main()
{
	freopen("input.txt", "r", stdin);

	int n, W, y1, y2, gap;
	bool flag;

	scanf("%d\n", &n);

	for(int i = 0; i < n; ++i)
	{
		if(i != 0)
			printf("\n");

		scanf("\n%d", &W);

		gap = 9999; flag = true;

		for(int w = 0; w < W; ++w)
		{
			scanf("%d %d", &y1, &y2);
			if(!flag) continue;
			if(9999 == gap) 
				gap = y1 - y2;
			else if(gap != y1-y2) 
				flag = false;
		}
		if(!flag)
			printf("no\n");
		else 
			printf("yes\n");
	}
	return 0;
}
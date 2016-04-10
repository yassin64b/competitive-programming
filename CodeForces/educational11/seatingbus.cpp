#include <cstdio>
#include <cmath>

int main()
{
	int n, m, limit;
	scanf("%d %d", &n, &m);

	limit = 2*n;
	if(limit > m)
		limit = m;

	for(int i = 1; i <= limit; ++i)
	{
		if(2*n + i <= m) 
			printf("%d ", 2*n+i);

		printf("%d ", i);
	}
}
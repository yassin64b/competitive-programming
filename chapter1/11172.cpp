#include <cstdio>

using namespace std;

int main()
{
	freopen("11172.txt", "r", stdin);
	
	int T;
	scanf("%d", &T);

	int x, y;
	while(scanf("%d %d", &x, &y) == 1)
	{
		printf("hi");
		if(x < y)
			printf("<");
		else
			x > y ? printf(">"): printf("=");
	}

	return 0;
}
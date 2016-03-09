#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);

	int n[4];
	int res = 0;

	while(scanf("%d %d %d %d", &n[0], &n[1], &n[2], &n[3]) != EOF)
	{
		if(n[0] == n[1] && n[1] == n[2] && n[2] == n[3] && n[3] == 0)
			break;

		res = 2*40;

		res += ((n[0] - n[1]) % 40 + 40) % 40;
		//printf("%d\t", (n[0] - n[1]) % 40);

		res += 40;
		
		res += ((n[2] - n[1]) % 40 + 40) % 40;

		res += ((n[2] - n[3]) % 40 + 40) % 40;


		printf("%d\n", res*9);
	}

	return 0;
}
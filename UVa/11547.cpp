#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	int N;

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		scanf("%d", &N);

		N = ((N) * 567 / 9 + 7492) * 235 / 47 - 498;

		
		printf("%d\n", abs(N/10 %10));
	}
}
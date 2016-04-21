#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;


int main()
{
	int N, K;

	scanf("%d %d", &N, &K);

	int v[500000];

	for(int i = 0; i < N; ++i)
		scanf("%d", &v[i]);

	int right = 0, left = 0;
	int j = 0, zerocount = 0;
	for(int i = 0; i < N; ++i)
	{
		if(j < i) 
		{
			j = i;
			zerocount = 0;
		}

		while(j < N)
		{
			if(zerocount + (v[j] == 0 ? 1 : 0) > K)
				break;
			zerocount += (v[j] == 0 ? 1 : 0);
			++j;
		}
		if(j - i > right - left)
			right = j, left = i;

		if(zerocount > 0 && v[i] == 0)
			zerocount -= 1;
	}

	printf("%d\n", right-left);

	for(int i = left; i < right; ++i)
		v[i] = 1;
	
	for(int i = 0; i < N; ++i)
		printf("%d ", v[i]);

	return 0;
}
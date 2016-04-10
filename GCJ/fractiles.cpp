#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int T, K, C, S;

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		scanf("%d %d %d", &K, &C, &S);

 		long long kc = 1;
 		for(int i = 0; i < C; ++i)
 			kc *= K;

 		printf("Case #%d:", t);

 		for(int i = 1; i <= K; ++i)
 			printf(" %d", i);
 		
 		printf("\n");
	}


	return 0;
}
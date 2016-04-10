#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <map>
#include <cmath>

using namespace std;

//works only for the small input
int main()
{
	int T, K, C, S;

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		scanf("%d %d %d", &K, &C, &S);
		
 		printf("Case #%d:", t);

 		for(int i = 1; i <= K; ++i)
 			printf(" %d", i);
 		
 		printf("\n");
	}


	return 0;
}
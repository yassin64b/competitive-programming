#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	int S, B;
	
	int left[100000+2], right[100000+2];
	while(scanf("%d %d", &S, &B) && (S || B))
	{
		for(int i = 1; i <= S; ++i)
			left[i] = i-1, right[i] = i+1;

		for(int i = 0; i < B; ++i)
		{
			int L, R;
			scanf("%d %d", &L, &R);
		
			if(left[L] > 0)
				printf("%d ", left[L]);
			else
				printf("* ");

			if(right[R] <= S)
				printf("%d\n", right[R]);
			else
				printf("*\n");

			left[right[R]] = left[L];
			right[left[L]] = right[R];
		}


		printf("-\n");
	}
}
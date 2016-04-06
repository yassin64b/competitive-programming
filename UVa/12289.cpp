#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);

	int N, res;
	char s[10];

	scanf("%d", &N);
		
	int count1, count2, count3;

	for(int n = 1; n <= N; ++n)
	{
		count1 = 0, count2 = 0, count3 = 0;

		scanf("%s", s);

		if(strlen(s) == 3)
		{
			if(s[0] == 'o' && (s[1] == 'n' || s[2] == 'e'))
				printf("1\n");
			else if(s[1] == 'n' && (s[0] == 'o' || s[2] == 'e'))
				printf("1\n");
			else
				printf("2\n");
		}
		else
			printf("3\n");
		
	}

	
}
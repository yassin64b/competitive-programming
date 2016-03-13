#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);

	int T, amount, account = 0;
	char s[10];

	scanf("%d", &T);
		
	for(int t = 1; t <= T; ++t)
	{
		scanf("%s", s);
		if(strcmp(s, "donate") == 0)
		{
			scanf("%d", &amount);
			account += amount;
		}	
		else
			printf("%d\n", account);

	}

	
}
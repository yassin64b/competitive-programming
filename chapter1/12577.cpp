#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);

	int T = 0;
	char s[10];
		
	while(scanf("%s", s) && ++T)
	{
		if(strcmp(s, "*") == 0) 
			break;
		else if(strcmp(s, "Hajj") == 0)
			printf("Case %d: Hajj-e-Akbar\n", T);
		else
			printf("Case %d: Hajj-e-Asghar\n", T);
	}

	
}
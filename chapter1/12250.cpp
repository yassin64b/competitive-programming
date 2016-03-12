#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);

	char s[15];
	int t = 0;

	while(scanf("%s", s) != EOF)
	{
		++t;

		if(strcmp("#", s) == 0)
			break;

		if(strcmp("HELLO", s) == 0)
			printf("Case %d: ENGLISH\n", t);
		else if(strcmp("HALLO", s) == 0)
			printf("Case %d: GERMAN\n", t);
		else if(strcmp("HOLA", s) == 0)
			printf("Case %d: SPANISH\n", t);
		else if(strcmp("BONJOUR", s) == 0)
			printf("Case %d: FRENCH\n", t);
		else if(strcmp("CIAO", s) == 0)
			printf("Case %d: ITALIAN\n", t);
		else if(strcmp("ZDRAVSTVUJTE", s) == 0)
			printf("Case %d: RUSSIAN\n", t);
		else
			printf("Case %d: UNKNOWN\n", t);
	}

	
}
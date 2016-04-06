#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);
	char s[10000];
	
	while(fgets(s, 9999, stdin) != NULL)
	{
		int i = 0;
		while(s[i] != '\0')
		{
			if(s[i] == '\n') s[i] = '\0';
			else s[i++] -= 7;
		}

		printf("%s\n", s);
	}
	return 0;
}
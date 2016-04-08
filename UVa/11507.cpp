#include <cstdio>
#include <cstring>

int main()
{
	int L, dir;
	char s[3], oldpos;

	while(scanf("%d", &L) != EOF && L)
	{
		oldpos = 'x'; dir = 1;

		for(int i = 0; i < L-1; ++i)
		{
			scanf("%s", s);
			
			if(s[0] == 'N') continue;

			if(oldpos == 'x' && s[0] == '-'
				|| oldpos == 'y' && strcmp(s, "+y") == 0
				|| oldpos == 'z' && strcmp(s, "+z") == 0)
				dir = -dir;

			if(oldpos == 'x') 
				oldpos = s[1];
			else if(oldpos == 'y' && s[1] == 'y' || oldpos == 'z' && s[1] == 'z')
				oldpos = 'x';
		}
		printf("%c%c\n", dir == 1 ? '+' : '-', oldpos);
	}
	return 0;
}
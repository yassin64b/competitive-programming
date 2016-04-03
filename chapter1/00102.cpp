#include <cstdio>
#include <cstring>

int x[9];
const char color[4] = "BGC";

int calc(int a, int b, int c)
{
    int res = 0;
    for ( int i = 0; i < 9; i++ )
        if ( i != a && i != b && i != c )
            res += x[i];
    
    return res;
}

int main()
{
	freopen("input.txt", "r", stdin);

	while(true)
	{
		for(int i = 0; i < 9; ++i)
			if(scanf("%d", x+i) == EOF)
				return 0;

		char s[4] = "ZZZ";
		long long cur, min = -1;
		int i,j,k;

		for(i = 0; i < 3; ++i)
		{
			for(j = 0; j < 3; ++j)
			{
				if(j == i) continue;

				for(k = 0; k < 3; ++k)
				{
					if(k == i || k == j) continue;

					cur = calc(i, j+3, k+6);

					char st[4] = {color[i], color[j], color[k], '\0'};
						
					if(cur < min || min == -1)
					{
						strcpy(s, st);
						min = cur; 
					} 
					else if(cur == min && strcmp(st, s) < 0) 
					{
						strcpy(s, st);
						min = cur;
					}
				}
			}
		}
		printf("%s %lld\n", s, min);	

	}
}
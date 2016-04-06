#include <cstdio>
#include <cstring>

int main()
{
	freopen("input.txt", "r", stdin);

	int n, off = 0;
	char p[101][102];

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%s", p[i]);

	for(int i = 0; i < (n-1) / 16 + 1; ++i)
	{
		for(int pos = 0; pos < 16; pos += 4)
		{
			printf("%s: Happy\n", p[(off+pos)%n]);
			printf("%s: birthday\n", p[(off+pos+1)%n]);
			printf("%s: to\n", p[(off+pos+2)%n]);
			if(pos%16 == 8)
				printf("%s: Rujia\n", p[(off+pos+3)%n]);
			else
				printf("%s: you\n", p[(off+pos+3)%n]);
		}	
		off += 16;
	}

	return 0;
}
#include <cstdio>
#include <cstring>

int main()
{
	freopen("input.txt", "r", stdin);

	int n, k;
	char s[10000];

	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		k = (int) strlen(s);

		if(strcmp(s, "1") == 0 || strcmp(s, "4") == 0 || strcmp(s, "78") == 0)
			printf("+\n");
		else if(s[k-2] == '3' && s[k-1] == '5')
			printf("-\n");
		else if(s[0] == '9' && s[k-1] == '4')
			printf("*\n");
		else if(s[0] == '1' && s[1] == '9' && s[2] == '0')
			printf("?\n");
	}
	return 0;
}
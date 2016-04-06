#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	char c;
	string line = "";
	int i = 0, flag = 0;

	while(scanf("%c", &c) != EOF)
	{
		if(c == 34)
		{
			if(!flag)
			{
				line += "``";
				flag = 1;
			}
			else
			{
				line += "''";
				flag = 0;
			}
			
		}
		else
			line += c;
		
		//printf("")
		if(c == '\n')
		{
			printf("%s", line.c_str());
			line = "";
		}
	}
	if(line != "")
		printf("%s", line.c_str());
}
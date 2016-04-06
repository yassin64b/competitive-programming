#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	char x[1000];
	int len;

	while(cin.getline(x, 1000))
		printf("%s\n", x);
	return 0;
}
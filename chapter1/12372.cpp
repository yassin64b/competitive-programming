#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);

	int T, L, W, H;

	scanf("%d", &T);
		
	for(int t = 1; t <= T; ++t)
	{
		scanf("%d %d %d", &L, &W, &H);

		if(L < 21 && H < 21 && W < 21)
			printf("Case %d: good\n", t);
		else
			printf("Case %d: bad\n", t);
	}

	
}
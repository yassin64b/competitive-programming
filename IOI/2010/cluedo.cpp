#include <cstdio>

/*int r1 = 3, r2 = 8, r3 = 2, count;

int Theory(int M, int L, int W)
{
	++count;

	if(M != r1)
		return 1;
	if(L != r2)
		return 2;
	if(W != r3)
		return 3;
	return 0;
}*/

//actual solution
void solve()
{
	int ret, G[3] = {1, 1, 1};
	//count = 0;

	while((ret = Theory(G[0], G[1], G[2])))
		++G[ret-1];

	return;
}
//end

/*
int main()
{
	solve();
	
	for(r1 = 1; r1 <= 6; ++r1)
		for(r2 = 1; r2 <= 10; ++r2)
			for(r3 = 1; r3 <= 6; ++r3)
			{
				solve();
				if(count > 20)
					printf("%d %d %d : %d\n", r1, r2, r3, count);
			}		
}*/
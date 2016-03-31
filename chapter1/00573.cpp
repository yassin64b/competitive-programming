#include <cstdio>


int main()
{
	freopen("input.txt", "r", stdin);

	double H, U, D, F, pos, Uorig;
	int i;

	while(scanf("%lf %lf %lf %lf", &H, &U, &D, &F) != EOF && H >= 1)
	{
		Uorig = U;
		pos = 0; i = 0;
		F /= 100.;
		while(pos <= H && pos >= 0)
		{
			//printf("%lf %lf %lf %lf\n", pos, U, D, F);
			++i;
			pos += U;
			if(pos > H) break;
			pos -= D;
			if((U -= Uorig*F) < 0) U = 0;
		}

		if(pos < 0)
			printf("failure on day %d\n", i);
		else
			printf("success on day %d\n", i);
	}	

	return 0;
}
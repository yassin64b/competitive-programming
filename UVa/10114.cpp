#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);

	int dur, T;
	double down, amount;
	

	

	while(scanf("%d %lf %lf %d", &dur, &down, &amount, &T) != -1)
	{
		if(dur <= 0) break;

		int mon;
		double depr[110] = {0}, val;


		for(int t = 0; t < T; t++)
		{
			scanf("%d %lf", &mon, &val);
			depr[mon] = val;
		}
		for(int i = 1; i <= dur; ++i)
			if(depr[i] == 0) depr[i] = depr[i-1]; 

		//printf("%d %lf %lf %d\n", dur, down, amount, T);
		//for(int t = 0; t <= dur; ++t)
		//	printf("%d %lf\n", t, depr[t]);
		
		int d = 0;
		double owe=amount, carval=(amount+down)-(amount+down)*depr[d];
		//printf("%lf %lf %lf\n", owe, carval, depr[d]);	
		for(d = 1; d <= dur; ++d)
		{
			if(carval > owe)
				break;	
			carval -= carval*depr[d];
			owe -= amount/dur;
			//printf("%lf %lf %lf\n", owe, carval, depr[d]);
			
			
			
			
		}
		--d == 1 ? printf("%d month\n", d) : printf("%d months\n", d);
	}

	return 0;
}
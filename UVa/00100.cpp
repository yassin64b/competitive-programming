#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 5000000

int main()
{
	ios::sync_with_stdio(false);

	int i, j;
	int *val = new int[SIZE];
	fill(val, val+SIZE, 0);

	while(scanf("%d %d", &i, &j) != EOF) 
	{
		int max = 0;

		cout << i << " " << j << " ";

		if(i > j)
			swap(i, j);

		for(; i <= j; ++i) 
		{
			int cycle = 1;
			long long res = i;

			while(res != 1)
			{
				if(res <= 0)
				{
					cout << "overflow" << endl;
					break;
				}
				if(res < SIZE && val[res] != 0)
				{
					cycle = cycle - 1 + val[res];
					break;
				}
				res = (res % 2 == 0 ? res / 2 : 3 * res + 1);
				++cycle;
			}
			val[i] = cycle;

			if(cycle > max)
				max = cycle;
		}
		cout << max << endl;
	}

}
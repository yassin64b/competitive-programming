#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
using namespace std;

int main()
{
	int B;
	cin >> B;

	for(int b = 0; b < B; ++b)
	{
		int s, sum = 0, val, opt = 0, ri = 0, rj = 0, j = 0;
		cin >> s;

		for(int i = 0; i < s-1; ++i)
		{
			cin >> val;
			sum += val;

			if(sum > opt || (sum == opt && i+1 - j > ri - rj))
				opt = sum, rj = j, ri = i+1;
			if(sum < 0)
				sum = 0, j = i+1;
		}
		if(opt > 0)
			cout << "The nicest part of route " << b+1 << " is between stops " << rj+1 << " and " << ri+1 << endl;
		else
			cout << "Route " << b+1 << " has no nice parts" << endl;			
	}
}
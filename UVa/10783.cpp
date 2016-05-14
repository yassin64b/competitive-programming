#include <iostream>
using namespace std;
int main()
{
	int T, a, b, sum;
	cin >> T;

	for(int t = 1; t <= T; ++t)
	{
		sum = 0;
		cin >> a >> b;
		a = (a%2 ? a : a+1);

		for( ; a <= b; a += 2)
			sum += a;

		cout << "Case " << t << ": " << sum << endl;
	}	
}
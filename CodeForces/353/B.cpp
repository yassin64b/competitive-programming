#include <iostream>
using namespace std;
typedef long long llng;
int main()
{
	llng a, b, c, d, n, sum = 0;
	cin >> n >> a >> b >> c >> d;

	for(int i = 1; i <= n; ++i)
	{
		llng topleft = a + b + i;
		llng topright = topleft - a - c;
		llng botleft = topleft - b - d;
		llng botright = topleft - c - d;

		if(topright >= 1 && topright <= n
			&& botleft >= 1 && botleft <= n
			&& botright >= 1 && botright <= n)
			sum += n;
	}

	cout << sum << endl;

	return 0;
}
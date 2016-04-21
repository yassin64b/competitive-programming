#include <iostream>

using namespace std;

int main()
{
	int h1, h2, a, b, day = 0;

	cin >> h1 >> h2 >> a >> b;

	if(a > b || h1 + a*8 >= h2)
	{
		while(h1 < h2)
		{
			h1 += a * 8;
			if(h1 >= h2) break;
			
			h1 -= b * 12;
			h1 += a * 4;
			++day;
		}
	}
	else 
		day = -1;

	cout << day << endl;

	return 0;
}
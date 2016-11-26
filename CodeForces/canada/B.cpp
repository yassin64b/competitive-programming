#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long n; char c;
	cin >> n >> c;
	long long x;
	if(n % 4 == 1)
	{
		x = (n+1) / 2;
	}
	else if(n % 4 == 3)
	{
		x = (n-1) / 2;
	}
	else if(n % 4 == 0)
	{
		x = n / 2;
	}
	else if(n % 4 == 2)
	{
		x = (n + 2) / 2;
	}
	long long res = (x-1) * 7 + ((x-1)/2) * 2;
	//cout << x << endl;
	//cout << res << endl;
	switch(c) {
		case 'a': case 'b': case 'c':
			res += (4 + c - 'a');
			break;
		case 'd': case 'e': case 'f':
			res += 1 + 'f' - c;
			break;
	}
	cout << res << endl;
	return 0;
}
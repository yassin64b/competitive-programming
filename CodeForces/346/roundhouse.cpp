#include <iostream>

using namespace std;

int main()
{
	int n, a, b, res;

	cin >> n >> a >> b;

	res = (a+b)%n;
	if(res == 0)
		res = n;
	else if(res < 0)
		res += n;

	cout << res << endl;
}
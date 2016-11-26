#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int a, b, s;
	cin >> a >> b >> s;
	
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;

	if (s >= a + b && (s - (a + b)) % 2 == 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int mod = k - (n % k);
	mod += n;

	cout << mod << endl; 

	return 0;
}
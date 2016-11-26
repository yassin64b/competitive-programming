#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> a(n+1, 0);
	int a12, a23, a13;

	cout << "? 1 2" << endl;
	fflush(stdout);
	cin >> a12;
	cout << "? 2 3" << endl;
	fflush(stdout);
	cin >> a23;
	cout << "? 1 3" << endl;
	fflush(stdout);
	cin >> a13;

	a[2] = (a12 + a23 - a13) / 2;
	a[1] = a12 - a[2];
	a[3] = a23 - a[2];

	for(int i = 4; i <= n; ++i)
	{
		int tmp;
		cout << "? 1 " << to_string(i) << endl;
		fflush(stdout);
		cin >> tmp;
		a[i] = tmp - a[1];
	}

	cout << "! ";
	for(int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
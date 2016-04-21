#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[1005], n;

	cin >> n;

	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	sort(a+1, a+n+1);

	for(int i = 1; i <= n/2; ++i)
	{
		cout << a[i] << " " << a[n-(i-1)] << " ";
	}
	if(n%2 == 1) cout << a[n/2+1];

	return 0;
}
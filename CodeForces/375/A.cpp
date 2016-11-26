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
	int x1, x2, x3;
	cin >> x1 >> x2 >> x3;

	int ans = 5000;
	for(int i = 1; i <= 100; ++i)
	{
		ans = min(ans, abs(x1 -i) + abs(x2 - i) + abs(x3-i));
	}
	cout << ans << endl;
	return 0;
}
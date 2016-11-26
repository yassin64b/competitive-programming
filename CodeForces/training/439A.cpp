#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n, d, time = 0;
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		time += t;
	}

	int ans = (n - 1) * 2;
	time += ans * 5;
	if (time <= d) {
		ans += (d - time) / 5;
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
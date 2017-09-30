#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int b, k, g;
	cin >> b >> k >> g;
	--b;
	
	cout << b / (k / g) + (b % (k / g) ? 1 : 0) << "\n";

	return 0;
}

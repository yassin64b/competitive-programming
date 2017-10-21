#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1 += x1 == x2;
	y1 += y1 == y2;
	cout << 2* (abs(x1 - x2) + 1 + abs(y1 - y2) + 1) << "\n";
}
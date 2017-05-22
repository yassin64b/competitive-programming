#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool query(int x, int y) {
	if (x == -1) {
		return false;
	}
	cout << 1 << " " << x << " " << y << endl;
	string ans;
	cin >> ans;
	return ans == "TAK";
}

int find(int x, int y) {
	if (x > y) return -1;
	while (x < y) {
		int mid = (x + y) / 2;
		if (query(mid, mid+1)) {
			y = mid;
		} else {
			x = mid + 1;
		}
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int x = find(1, n);
	int y = find(1, x-1);
	if (!query(y, x)) {
		y = find(x+1, n);
	}

	cout << 2 << " " << x << " " << y << endl;


	return 0;
}
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int X;
	cin >> X;

	int res = 0;
	for (int i = 2; i * i <= X; ++i) {
		while (X % i == 0) {
			++res;
			X /= i;
		}
	}
	res += (X > 1);
	cout << res << "\n";
}
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
	}
	vector<vector<int>> plane(n, vector<int>(9, -1));
	int row = 0;

	for (int i = 0; i < k; ++i) { //4 in 4
		while (a[i] >= 4 && row < n) {
			for (int j = 3; j <= 6; ++j) {
				plane[row][j] = i;
			}
			a[i] -= 4;
			++row;
		}
	}
	for (int i = 0; i < k; ++i) { //3 in 4
		while (a[i] >= 3 && row < n) {
			for (int j = 3; j <= 5; ++j) {
				plane[row][j] = i;
			}
			a[i] -= 3;
			++row;
		}
	}
	for (int i = 0; i < k; ++i) { //2 in 4
		while (a[i] >= 2 && row < n) {
			for (int j = 3; j <= 4; ++j) {
				plane[row][j] = i;
			}
			a[i] -= 2;
			++row;
		}
	}

	row = 0;
	for (int i = 0; i < k; ++i) { //2 in 2
		while (a[i] >= 2 && row < n) {
			for (int j = 1; j <= 2; ++j) {
				plane[row][j] = i;
			}
			a[i] -= 2;
			++row;
		}
	}
	
	row = 0;
	for (int i = 0; i < k; ++i) { //2 in 2
		while (a[i] >= 2 && row < n) {
			for (int j = 7; j <= 8; ++j) {
				plane[row][j] = i;
			}
			a[i] -= 2;
			++row;
		}
	}

	row = 0;
	for (int i = 0; i < k; ++i) { //1 anywhere
		while (a[i] >= 1 && row < n) {
			if (plane[row][1] == -1 && plane[row][2] == -1) {
				plane[row][1] = i;
				--a[i];
			} else if (plane[row][3] == -1 && plane[row][4] == -1) {
				plane[row][3] = i;
				--a[i];
			} else if (plane[row][6] == -1 && plane[row][5] == -1) {
				plane[row][6] = i;
				--a[i];
			} else if (plane[row][8] == -1 && plane[row][7] == -1) {
				plane[row][8] = i;
				--a[i];
			} else {
				++row;
			}
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= 8; ++j) {
			cout << plane[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = 0; i < k; ++i) {
		if (a[i] > 0) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";


	return 0;
}
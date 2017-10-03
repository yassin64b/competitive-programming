#include <iostream>
#include <vector>

using namespace std;

constexpr int SZ = 8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> board(SZ);
	for (int i = 0; i < SZ; ++i) {
		cin >> board[i];
	}
	int numQueens = 0;
	bool valid = true;
	for (int i = 0; i < SZ; ++i) {
		for (int j = 0; j < SZ; ++j) {
			if (board[i][j] == '*') {
				++numQueens;
				for (int k = 0; k < SZ; ++k) {
					if (k != j && board[i][k] == '*') { //row
						valid = false;
					}
					if (k != i && board[k][j] == '*') { //column
						valid = false;
					}
				}
				for (int k = -SZ + 1; k < SZ; ++k) {
					int ii = i + k, jj = j + k;
					if (k != 0 && ii >= 0 && ii < SZ && jj >= 0 && jj < SZ) {
						if (board[ii][jj] == '*') {
							valid = false;
						}
					}
					ii = i + k;
					jj = j - k;
					if (k != 0 && ii >= 0 && ii < SZ && jj >= 0 && jj < SZ) {
						if (board[ii][jj] == '*') {
							valid = false;
						}
					}
				}
			}
		}
	}
	cout << ((valid && numQueens == 8) ? "valid\n" : "invalid\n");
}
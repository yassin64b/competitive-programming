#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> f(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> f[i][j];
		}
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int cur = 0;
		for (int j = 0; j < m; ++j) {
			if (f[i][j] == '0') {
				++cur;
			} else {
				res += cur;
				cur = 0;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		int cur = 0;
		for (int j = 0; j < m; ++j) {
			if (f[i][m-j-1] == '0') {
				++cur;
			} else {
				res += cur;
				cur = 0;
			}
		}
	}
	for (int j = 0; j < m; ++j) {
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (f[i][j] == '0') {
				++cur;
			} else {
				res += cur;
				cur = 0;
			}
		}
	}
	for (int j = 0; j < m; ++j) {
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (f[n-i-1][j] == '0') {
				++cur;
			} else {
				res += cur;
				cur = 0;
			}
		}
	}

	cout << res << endl;
   
    return 0;
}
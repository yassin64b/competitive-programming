#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	map<char, int> m;
	for (int i = 0; i < n; ++i)
		++m[s[i]];
	int uneven = 0;
	for (const auto& p : m) {
		uneven += p.second % 2;
	}
	for (int len = n; len > 0; --len) {
		if (n % len == 0) {
			int k = n / len;
			bool poss = false;
			if (len % 2 == 0) {
				if (!uneven) {
					poss = true;
				}
			} else {
				if (uneven <= k) {
					poss = true;
				}
			}
			if (poss) {
				cout << k << "\n";
				vector<string> res(k, string(len, '_'));
				for (int i = 0; i < k; ++i) {
					for (int j = 0; j < len / 2; ++j) {
						for (const auto& p : m) {
							if (p.second >= 2) {
								res[i][j] = res[i][len - j - 1] = p.first;
								m[p.first] -= 2;
								break;
							}
						}
					}
				}
				if (len % 2) {
					for (int i = 0; i < k; ++i) {
						for (const auto& p : m) {
							if (p.second >= 1) {
								res[i][len / 2] = p.first;
								m[p.first] -= 1;
								break;
							}
						}
					}
				}
				for (int i = 0; i < k; ++i) {
					cout << res[i] << " ";
				}
				cout << "\n";
				return 0;
			}
		}
	}
	assert(false);
}
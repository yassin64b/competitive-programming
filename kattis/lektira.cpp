#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	string res = s;
	int n = s.size();
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			string s1 = s.substr(0, i);
			string s2 = s.substr(i, j - i);
			string s3 = s.substr(j);
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());
			if (s1 + s2 + s3 < res) {
				res = s1 + s2 + s3;
			}
		}
	}
	cout << res << "\n";

	return 0;
}

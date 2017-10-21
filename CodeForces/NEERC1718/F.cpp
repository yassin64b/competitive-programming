#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> w(n);
	unordered_set<string> s;
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		while (1) {
			if (w[i].find("u") != string::npos) {
				w[i].replace(w[i].find("u"), 1, "oo");
				continue;
			}
			if (w[i].find("kh") != string::npos) {
				w[i].replace(w[i].find("kh"), 2, "h");
				continue;
			}
			break;
		}
		s.insert(w[i]);
	}
	cout << s.size() << "\n";
}
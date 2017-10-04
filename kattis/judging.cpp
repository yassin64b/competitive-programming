#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

constexpr int PROCT = 1000;
constexpr int MAXT = 100000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	unordered_map<string, int> dom;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		++dom[s];
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (dom.find(s) != dom.end()) {
			if (dom[s] > 0) {
				++res;
				--dom[s];
			}
		}
	}
	cout << res << "\n";
}